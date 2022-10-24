#!/usr/bin/env python3

# Copyright (C) 2021 TomTom NV. All rights reserved.
#
# This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
# used for internal evaluation purposes or commercial use strictly subject to separate
# license agreement between you and TomTom NV. If you are the licensee, you are only permitted
# to use this software in accordance with the terms of your license agreement. If you are
# not the licensee, you are not authorized to use this software in any manner and should
# immediately return or destroy it.

from src.convert_dita_to_po import *
import unittest
from collections import namedtuple
from parameterized import parameterized


class TestGetMessageDetails(unittest.TestCase):
    def test(self):
        input_str = "Follow {road_number} for {distance}."
        expected = {"msgctxt": "",
                    "msgid": "Follow {road_number} for {distance}.",
                    "msgid_plural": "",
                    "msgstr_quantity": ""}
        actual = get_message_details(input_str)

        self.assertEqual(actual, expected)

    def test_with_msg_context(self):
        input_str = "second_freeway_exit➖Take the left exit onto {road_number} toward {toward_name}."
        expected = {"msgctxt": "second_freeway_exit",
                    "msgid": "Take the left exit onto {road_number} toward {toward_name}.",
                    "msgid_plural": "",
                    "msgstr_quantity": ""}
        actual = get_message_details(input_str)

        self.assertEqual(actual, expected)

    def test_with_msg_id_plural(self):
        input_str = "after {distance}➖{count} mile➖{count} miles➖zero"
        expected = {"msgctxt": "after {distance}",
                    "msgid": "{count} mile",
                    "msgid_plural": "{count} miles",
                    "msgstr_quantity": "zero"}
        actual = get_message_details(input_str)

        self.assertEqual(actual, expected)

    def test_direction_details(self):
        input_str = "exit_highway➖onto {road_number} toward {toward_name}."
        expected = {"msgctxt": "exit_highway",
                    "msgid": "onto {road_number} toward {toward_name}.",
                    "msgid_plural": "",
                    "msgstr_quantity": ""}
        actual = get_message_details(input_str)

        self.assertEqual(actual, expected)


class TestIsMsgIdAvailableInPoFile(unittest.TestCase):
    MockEntry = namedtuple('MockEntry', 'msgctxt msgid msgid_plural msgstr')

    @parameterized.expand([
        ("Only msgid available", MockEntry(None, "MSGID", None, ""),
         {"msgctxt": None, "msgid": "MSGID", "msgid_plural": None, "msgstr_quantity": ""}, True),
        ("Wrong msgid available", MockEntry(None, "MSGID", None, ""),
         {"msgctxt": None, "msgid": "Wrong MSGID", "msgid_plural": None, "msgstr_quantity": ""}, False),

        ("msgctxt and msgid is available", MockEntry("MSGCTXT", "MSGID", None, ""),
         {"msgctxt": "MSGCTXT", "msgid": "MSGID", "msgid_plural": None, "msgstr_quantity": ""}, True),
        ("Wrong msgctxt, msgctxt and msgid is available", MockEntry("MSGCTXT", "MSGID", None, ""),
         {"msgctxt": "Wrong MSGCTXT", "msgid": "MSGID", "msgid_plural": None, "msgstr_quantity": ""}, False),
        ("Wrong msgid, msgctxt and msgid is available", MockEntry("MSGCTXT", "MSGID", None, ""),
         {"msgctxt": "MSGCTXT", "msgid": "Wrong MSGID", "msgid_plural": None, "msgstr_quantity": ""}, False),

        ("msgctxt, msgid and msgid_plural is available", MockEntry("MSGCTXT", "MSGID", "MSGID_PLURAL", ""),
         {"msgctxt": "MSGCTXT", "msgid": "MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": ""}, True),
        ("Wrong msgid_plural, msgctxt, msgid and msgid_plural is available",
         MockEntry("MSGCTXT", "MSGID", "MSGID_PLURAL", ""),
         {"msgctxt": "MSGCTXT", "msgid": "MSGID", "msgid_plural": "Wrong MSGID_PLURAL", "msgstr_quantity": ""}, False),
        ("Wrong msgid, msgctxt, msgid and msgid_plural is available", MockEntry("MSGCTXT", "MSGID", "MSGID_PLURAL", ""),
         {"msgctxt": "MSGCTXT", "msgid": "Wrong MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": ""}, False),
        ("Wrong msgctxt, msgctxt, msgid and msgid_plural is available",
         MockEntry("MSGCTXT", "MSGID", "MSGID_PLURAL", ""),
         {"msgctxt": "Wrong MSGCTXT", "msgid": "MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": ""}, False)
    ])
    def test(self, _name, entry, message_details, expected_items):
        self.maxDiff = None
        actual = is_msg_id_available_in_po_file(entry, message_details)
        self.assertEqual(expected_items, actual)


class TestUpdateMessageString(unittest.TestCase):
    class MockEntry:
        __slots__ = ['msgctxt', 'msgid', 'msgid_plural', 'msgstr', 'msgstr_plural']

        def __init__(self, msgctxt, msgid, msgid_plural, msgstr, msgstr_plural):
            self.msgctxt = msgctxt
            self.msgid = msgid
            self.msgid_plural = msgid_plural
            self.msgstr = msgstr
            self.msgstr_plural = msgstr_plural

    @parameterized.expand([
        ("No plural msgid", "en-GB", MockEntry(None, "MSGID", None, "", {}),
         {"msgctxt": None, "msgid": "MSGID", "msgid_plural": "", "msgstr_quantity": ""}, "Simple message"),
        ("Plural msgid with one message quantity", "en-GB", MockEntry(None, "MSGID", None, "", {}),
         {"msgctxt": None, "msgid": "MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": "one"},
         "msgstr_plural[0]"),
        ("Plural msgid with other message quantity", "en-GB", MockEntry(None, "MSGID", None, "", {}),
         {"msgctxt": None, "msgid": "MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": "other"},
         "msgstr_plural[1]"),
        ("Plural msgid with cs-CZ language and one message quantity", "cs-CZ", MockEntry(None, "MSGID", None, "", {}),
         {"msgctxt": None, "msgid": "MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": "one"}, "cs-CZ-one"),
        ("Plural msgid with cs-CZ language and few message quantity", "cs-CZ", MockEntry(None, "MSGID", None, "", {}),
         {"msgctxt": None, "msgid": "MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": "few"}, "cs-CZ-few"),
        ("Plural msgid with cs-CZ language and other message quantity", "cs-CZ", MockEntry(None, "MSGID", None, "", {}),
         {"msgctxt": None, "msgid": "MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": "other"},
         "cs-CZ-other"),
        ("Plural msgid with pl-PL language and one message quantity", "pl-PL", MockEntry(None, "MSGID", None, "", {}),
         {"msgctxt": None, "msgid": "MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": "one"}, "pl-PL-one"),
        ("Plural msgid with pl-PL language and few message quantity", "pl-PL", MockEntry(None, "MSGID", None, "", {}),
         {"msgctxt": None, "msgid": "MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": "few"}, "pl-PL-few"),
        ("Plural msgid with pl-PL language and many message quantity", "pl-PL", MockEntry(None, "MSGID", None, "", {}),
         {"msgctxt": None, "msgid": "MSGID", "msgid_plural": "MSGID_PLURAL", "msgstr_quantity": "many"}, "pl-PL-many"),
    ])
    def test(self, _name, lang, entry, message_details, message_translation):
        update_message_string(lang, entry, message_details, message_translation)
        if message_details["msgid_plural"]:
            if message_details["msgstr_quantity"] == "one":
                self.assertEqual(entry.msgstr_plural[0], message_translation)
            elif message_details["msgstr_quantity"] == "few":
                self.assertEqual(entry.msgstr_plural[1], message_translation)
            elif message_details["msgstr_quantity"] == "many":
                self.assertEqual(entry.msgstr_plural[2], message_translation)
            elif message_details["msgstr_quantity"] == "other":
                self.assertEqual(entry.msgstr_plural[1] if lang != "cs-CZ" else entry.msgstr_plural[2],
                                 message_translation)
        else:
            self.assertEqual(entry.msgstr, message_translation)


if __name__ == '__main__':
    unittest.main()
