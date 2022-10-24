# Copyright (C) 2021 TomTom NV. All rights reserved.
#
# This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
# used for internal evaluation purposes or commercial use strictly subject to separate
# license agreement between you and TomTom NV. If you are the licensee, you are only permitted
# to use this software in accordance with the terms of your license agreement. If you are
# not the licensee, you are not authorized to use this software in any manner and should
# immediately return or destroy it.

import os
import polib
from lxml import etree
import src.separator as separator

lang_plural_form_mapping = {
    "ar-SA": ["zero", "one", "two", "few", "many", "other"],
    "cs-CZ": ["one", "few", "other"],
    "pl-PL": ["one", "few", "many"],
    "sl-SI": ["one", "two", "few", "other"],
    "ru-RU": ["one", "few", "many"],
    "uk-UA": ["one", "few", "many"]
}
"""
Some of the languages have more than two plural forms, so we need to create 
the mapping of language code to quantity strings supported by that language.
See this page: https://unicode-org.github.io/cldr-staging/charts/latest/supplemental/language_plural_rules.html
"""


def get_message_details(id_text):
    """
    Get the message details such as msgctxt, msgid, msgid_plural, msgstr_quantity.
    Value for `msgid` will be always there while other field can be empty.

    Param id_text: The text inside `id` attribute of `uicontrol` element from xml
    Returns: Map of po format keyword and its value 
    Return type: map
    """
    msg_details = {"msgctxt": "",
                   "msgid": "",
                   "msgid_plural": "",
                   "msgstr_quantity": ""}

    msg_details_list = id_text.split(separator.id_separator)
    if msg_details_list is None:
        print("Warning: message id is empty in xml file.")
        return {}

    if len(msg_details_list) == 1:
        msg_details["msgid"] = msg_details_list[0]
    else:
        msg_details["msgctxt"] = msg_details_list[0]
        msg_details["msgid"] = msg_details_list[1]
        if len(msg_details_list) >= 3:
            msg_details["msgid_plural"] = msg_details_list[2]
            msg_details["msgstr_quantity"] = msg_details_list[3]

    return msg_details


def is_msg_id_available_in_po_file(entry, message_details):
    """
    This function checks if required PO file attributes are available.
    Param entry: Entry from the PO file 
    Param message_details: Message details to search for
    Returns: True if message_details is same as entry otherwise false
    Return type: bool
    """
    return entry and (entry.msgid == message_details["msgid"]
                      and (entry.msgctxt is None or entry.msgctxt is not None
                           and entry.msgctxt == message_details["msgctxt"])
                      and entry.msgid_plural == message_details["msgid_plural"])


def update_message_string(lang, entry, message_details, message_translation):
    """
    This function update the message string from PO file entry. If the message details contains
    plural message id then `msgstr_plural` is updated.

    Param lang: Language code.
    Param entry: Entry from the PO file.
    Param message_details: Message details from xml file.
    Param message_translation: Translated message string from xml file.
    Returns: None
    Return type: None
    """
    if message_details["msgid_plural"]:
        if lang in lang_plural_form_mapping:
            plural_catagory = lang_plural_form_mapping.get(lang)
            if message_details["msgstr_quantity"] in plural_catagory:
                index = plural_catagory.index(
                    message_details["msgstr_quantity"])
                entry.msgstr_plural[index] = message_translation
        elif "one" == message_details["msgstr_quantity"]:
            entry.msgstr_plural[0] = message_translation
        elif "other" == message_details["msgstr_quantity"]:
            entry.msgstr_plural[1] = message_translation
    else:
        entry.msgstr = str(message_translation)


def update_po_file(po_output, language, message_details, message_translation):
    """
    This function update PO file with translation.

    Param po_file: Parse PO file instance
    Param language: translation language
    Param message_details: Message details from xml file.
    Param message_translation: Translated message string from xml file.
    Returns: None
    Return type: None
    """
    if message_details["msgctxt"]:
        entries = po_output.find(
            st=message_details["msgid"], msgctxt=message_details["msgctxt"])
    else:
        entries = po_output.find(st=message_details["msgid"])

    if type(entries) is list:
        for entry in entries:
            if is_msg_id_available_in_po_file(entry, message_details):
                update_message_string(
                    language, entry, message_details, message_translation)
    else:
        if is_msg_id_available_in_po_file(entries, message_details):
            update_message_string(
                language, entries, message_details, message_translation)


def convert_dita_to_po(input_str, output):
    """
    This function updates the PO file with translation taken from XML format.

    Param input: DITA format xml file.
    Param output: PO file to update.
    Returns: None
    Return type: None
    """
    tree = etree.parse(input_str)
    root = tree.getroot()

    po_output = polib.pofile(output, wrapwidth=1000)
    language = os.path.splitext(os.path.basename(output))[-2]

    for child in root.iter("uicontrol"):
        message_details = get_message_details(child.attrib.get('id'))
        if not message_details:
            continue

        message_translation = child.text
        if not message_translation:
            continue

        update_po_file(po_output, language,
                       message_details, message_translation)

    po_output.save()
