# Copyright (C) 2021 TomTom NV. All rights reserved.
#
# This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
# used for internal evaluation purposes or commercial use strictly subject to separate
# license agreement between you and TomTom NV. If you are the licensee, you are only permitted
# to use this software in accordance with the terms of your license agreement. If you are
# not the licensee, you are not authorized to use this software in any manner and should
# immediately return or destroy it.

import polib
import re
import src.separator as separator
from collections import namedtuple
from lxml import etree

Item = namedtuple('Item', 'id text description')
"""Tuple with named fields: 'id', 'text', 'description'"""

context_map = {
    "{landmark}":
        "Used as a substitute of {landmark} placeholder. Ex.:"
        " 'In 100 meters {landmark} bear right.' -> 'In 100 meters at the end of the road bear right.'",
    "{roundabout_exit_number_v2}":
        "Ordinal number used as a substitute of {roundabout_exit_number_v2} variable.",
    "{roundabout_exit_number}":
        "Ordinal number used as a substitute of {roundabout_exit_number} variable.",
    "In {distance}":
        "Distance string used as a substitute of {distance} variable in messages like"
        " 'In {distance} turn left.'",
    "follow for {distance}":
        "Distance string used as a substitute of {distance} variable in messages like"
        " 'Follow the road for {distance}.'",
    "after {distance}":
        "Distance string used as a substitute of {distance} variable in messages like"
        " 'You will reach a ferry after {distance}.'",
    "you are entering {country}":
        "Country name used as a substitute of {country} variable in messages like"
        " 'You are entering {country}.'",
    "delays of {delay}":
        "Time in hours and/or minutes used as a substitute of {delay} variable in messages like"
        " 'The route contains traffic delays of {delay}.'",
    "There is an alternative route with a faster arrival time of {advantage}.":
        "Time in hours and/or minutes used as a substitute of {advantage} variable in messages like"
        " 'There is an alternative route with a faster arrival time of {advantage}.'",
    "of {speed_limit}":
        "Speed in km/h or miles/h used as a substitute of {speed} variable in messages like"
        " 'The speed limit is {speed_limit}'.",
    "The route contains {avoid_criterion}":
        "Road type, used as a substitute of {avoid_criterion}, {avoid_criterion_2}... variables in messages like"
        " 'Attention! The route contains {avoid_criterion}, {avoid_criterion_2} and {avoid_criterion_3}.'",
    "The route contains {allow_criterion}":
        "Road type, used as a substitute of {allow_criterion} variable in messages like"
        " 'The route contains {allow_criterion} and {allow_criterion_2}.'"
}
"""
Additional explanation for messages with message contexts. 
Translators can't see msgctxt, therefore those messages should be supplied with a visible comment.
"""

DirectionDetailsDescriptionParam = namedtuple(
    'DirectionDetailsDescriptionParam', 'instruction_type example_msg')
"""Tuple with named fields: 'instruction_type', 'example_msg'"""

direction_details_param_map = {
    "{direction_details} for fork":
        DirectionDetailsDescriptionParam(
            " street furcation", "'In {distance} keep left {direction_details}.'"),
    "{direction_details} for exit highway":
        DirectionDetailsDescriptionParam(
            " exit", "'Take the exit {direction_details}.'"),
    "{direction_details} for turn: go straight":
        DirectionDetailsDescriptionParam(
            " go straight", "'Go straight {direction_details}.'"),
    "{direction_details} for turn: left, right":
        DirectionDetailsDescriptionParam(
            " turn", "'Turn right {direction_details}.'"),
    "{direction_details} for U-turn":
        DirectionDetailsDescriptionParam(
            " U-turn", "'Make a U-turn {direction_details}.'"),
    # default param when no default instruction exists
    "{direction_details}":
        DirectionDetailsDescriptionParam("",
                                         "'In {distance} exit the roundabout {direction_details}.', "
                                         "'At the roundabout in {distance} go straight, "
                                         "{roundabout_exit_number} exit {direction_details}.', "
                                         "In {distance} take the exit {direction_details}.")}

direction_details_msgids = ["and continue to follow {road_name_preposition_and_article_for_follow_case} {road_name_for_follow_case} toward {toward_name}",
                            "and continue to follow {road_name_preposition_and_article_for_follow_case} {road_name_for_follow_case}",
                            "to stay on {road_number} toward {toward_name}",
                            "to stay on {road_number}",
                            "to stay on {road_name} toward {toward_name}",
                            "to stay on {road_name}",
                            "onto {road_number} toward {toward_name}",
                            "onto {road_number}",
                            "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case} toward "
                            "{toward_name}",
                            "{road_name_preposition_and_article_for_into_case} {road_name_for_into_case}",
                            "onto {road_name} toward {toward_name}",
                            "onto {road_name}",
                            "toward {toward_name}"]
"""Msgids of direction details."""

direction_details_description_template = ("String used as a substitute of {direction_details} variable "
                                          "in%(instruction_type)s messages like %(example_msg)s")
"""Additional explanation for direction details variable."""


def find_all_placeholders(text):
    """Returns list of all variables in provided text"""
    return re.findall(r'({[a-z_2]+})', text)


def normalize_text(text):
    """Replace 'variables' to correct form $OneOfTheBestVariable#"""
    placeholders = find_all_placeholders(text)
    for placeholder in placeholders:
        # Remove special character
        placeholder_text = re.sub(r'[{}]', '', placeholder)
        placeholder_text = re.sub(
            r"_", " ", placeholder_text).title().replace(" ", "")
        placeholder_text = "$" + placeholder_text + "#"
        text = text.replace(placeholder, placeholder_text)

    return text


def get_context_description(msgctxt):
    """Returns:
        description of message contexts, if have one
    """
    if msgctxt in context_map:
        return context_map[msgctxt]
    return ""


def get_direction_details_description(msgctxt, msgid):
    """Returns:
        description of direction details message, empty string if the input is not direction details
    """
    if msgid in direction_details_msgids and msgctxt in direction_details_param_map:
        print('getDirectionDetailsDescription: ctxt: {}'.format(msgctxt))
        param = direction_details_param_map[msgctxt]
        return direction_details_description_template % {"instruction_type": param.instruction_type,
                                                         "example_msg": param.example_msg}

    return ""


def create_screen_sub_element(screen_element, unique_id, text, description):
    """Adds subelement 'uicontrol' to 'screen_element' with 'unique_id', 'text' and 'description'"""
    uicontrol_element = etree.SubElement(
        screen_element, "uicontrol", id=unique_id, translate="yes", otherprops="")
    uicontrol_element.text = text

    fn_element = etree.SubElement(screen_element, "fn")
    fn_element.text = description


def create_plural_description(msgctxt, category):
    """Creates description for plural messages"""
    template_description_string = (
        "(Spoken Text)%(context)s "
        "Use plural form of units for the cardinal number {count}"
        " from the category %(plural_form_comment)s. "
        "Keep empty, if the target language does not have this category,"
        " see full list of categories: "
                                   "https://unicode-org.github.io/cldr-staging/charts/latest/supplemental/language_plural_rules.html. "
                                   )

    context_comment = get_context_description(msgctxt)
    if context_comment != "":
        return template_description_string % {"context": " " + context_comment,
                                              "plural_form_comment": "'" + category + "'"}

    return template_description_string % {"context": "", "plural_form_comment": "'" + category + "'"}


def get_data(entry):
    """Returns list of 'Item' elements that is generated from input.
    For plurals the 6 items are returned for each plural case: zero, one, two, few, many, other.
    For singular 1 item is returned.
    """
    ret = []
    if entry.msgid_plural:
        for category in ["zero", "one", "two", "few", "many", "other"]:
            unique_id = separator.id_separator.join(filter(None,
                                                           [entry.msgctxt, entry.msgid, entry.msgid_plural, category]))
            uicontrol_element_text = entry.msgstr_plural[0] if category == "one" else entry.msgstr_plural[1]
            description = create_plural_description(entry.msgctxt, category)

            ret.append(Item(unique_id, uicontrol_element_text, description))
    else:
        unique_id = separator.id_separator.join(
            filter(None, [entry.msgctxt, entry.msgid]))
        uicontrol_element_text = entry.msgstr
        description = "(Spoken Text)"
        context = get_context_description(entry.msgctxt)
        if context != "":
            description = description + " " + context

        direction_details = get_direction_details_description(entry.msgctxt, entry.msgid)
        if direction_details != "":
            description = description + " " + direction_details

        ret.append(Item(unique_id, uicontrol_element_text, description))

    return ret


def convert_po_to_dita(template, output):
    """Converts 'template' po file to 'output' xml."""
    po_template = polib.pofile(template)

    root = etree.Element("dita")
    root.attrib["{http://www.w3.org/XML/1998/namespace}lang"] = "en-GB"
    topic = etree.SubElement(
        root, "topic", product="NAVKIT2.tomtom.com", rev="0.0.1")
    body = etree.SubElement(topic, "body")
    screen = etree.SubElement(body, "screen")

    for entry in po_template:
        for item in get_data(entry=entry):
            create_screen_sub_element(
                screen_element=screen, unique_id=item.id, text=item.text, description=item.description)

    f = open(output, 'w')
    f.write(etree.tostring(root, pretty_print=True,
                           xml_declaration=True, encoding="UTF-8").decode("utf-8"))
    f.close()
