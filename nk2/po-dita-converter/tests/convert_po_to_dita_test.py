#!/usr/bin/env python3

# Copyright (C) 2021 TomTom NV. All rights reserved.
#
# This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
# used for internal evaluation purposes or commercial use strictly subject to separate
# license agreement between you and TomTom NV. If you are the licensee, you are only permitted
# to use this software in accordance with the terms of your license agreement. If you are
# not the licensee, you are not authorized to use this software in any manner and should
# immediately return or destroy it.

import src.convert_po_to_dita as po_to_dita
import unittest
from collections import namedtuple
from parameterized import parameterized


class TestNormalizeText(unittest.TestCase):
    def test(self):
        input_str = \
            "At the roundabout in {distance} turn left, "\
            "{roundabout_exit_number_v2} exit {road_name_preposition} {road_name}."
        expected = \
            "At the roundabout in $Distance# turn left, $RoundaboutExitNumberV2# exit $RoadNamePreposition# $RoadName#."
        actual = po_to_dita.normalize_text(input_str)

        self.assertEqual(actual, expected)


class TestGetContextDescription(unittest.TestCase):
    def test_empty_input(self):
        actual = po_to_dita.get_context_description("")
        expected = ""

        self.assertEqual(actual, expected)

    def test_input_none(self):
        actual = po_to_dita.get_context_description(None)
        expected = ""

        self.assertEqual(actual, expected)

    def test_input_is_not_present_in_context_map(self):
        input_str = "FooBla"
        actual = po_to_dita.get_context_description(input_str)

        self.assertEqual(actual, "")

    def test_all_input_from_context_map(self):
        for key in po_to_dita.context_map:
            actual = po_to_dita.get_context_description(key)
            expected = po_to_dita.context_map[key]

            self.assertEqual(actual, expected)


class TestContextMap(unittest.TestCase):
    def test_keys(self):
        expected_keys = ["{landmark}",
                         "{roundabout_exit_number_v2}",
                         "{roundabout_exit_number}",
                         "In {distance}",
                         "follow for {distance}",
                         "after {distance}",
                         "you are entering {country}",
                         "delays of {delay}",
                         "There is an alternative route with a faster arrival time of {advantage}.",
                         "of {speed_limit}",
                         "The route contains {avoid_criterion}",
                         "The route contains {allow_criterion}"]
        self.assertEqual(len(expected_keys), len(po_to_dita.context_map))
        for expected_key in expected_keys:
            self.assertTrue(expected_key in po_to_dita.context_map)


class TestDirectionDetailsDescription(unittest.TestCase):
    def test_msgids(self):
        expected_msgids = ["and continue to follow {road_name_preposition_and_article_for_follow_case} {road_name_for_follow_case} toward {toward_name}",
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
        self.assertEqual(len(expected_msgids), len(po_to_dita.direction_details_msgids))
        for msgid in expected_msgids:
            self.assertTrue(msgid in po_to_dita.direction_details_msgids)

    def test_msgid_is_not_present(self):
        msgctxt = "{direction_details}"
        msgid = "FooBla"
        actual = po_to_dita.get_direction_details_description(msgctxt, msgid)

        self.assertEqual(actual, "")

    def test_msgid_is_none(self):
        msgctxt = "{direction_details}"
        msgid = None
        actual = po_to_dita.get_direction_details_description(msgctxt, msgid)

        self.assertEqual(actual, "")

    def test_msgctxt_is_not_present(self):
        msgctxt = "FooBla"
        msgid = "onto {road_number}"
        actual = po_to_dita.get_direction_details_description(msgctxt, msgid)

        self.assertEqual(actual, "")

    def test_msgctxt_is_none(self):
        msgctxt = None
        msgid = "onto {road_number}"
        actual = po_to_dita.get_direction_details_description(msgctxt, msgid)

        self.assertEqual(actual, "")

    def test_all_input_from_direction_details_msgids(self):
        for msgid in po_to_dita.direction_details_msgids:
            for msgctxt in po_to_dita.direction_details_param_map:
                actual = po_to_dita.get_direction_details_description(msgctxt, msgid)
                param = po_to_dita.direction_details_param_map[msgctxt]
                expected_description = (po_to_dita.direction_details_description_template %
                                        {"instruction_type": param.instruction_type,
                                         "example_msg": param.example_msg})

                self.assertEqual(actual, expected_description)


class TestGetData(unittest.TestCase):
    MockEntry = namedtuple(
        'MockEntry', 'msgctxt msgid msgid_plural msgstr msgstr_plural')

    @parameterized.expand([
        ("no plural, no context, msgstr in template is not empty", MockEntry(None, "MSGID", None,
                                                                             "TEMPLATE_STR", None),
         [po_to_dita.Item("MSGID", "TEMPLATE_STR", "(Spoken Text)")]),

        ("no plural, context is present, msgstr in template is not empty", MockEntry("CONTEXT",
                                                                                     "MSGID", None, "STR", None),
         [po_to_dita.Item("CONTEXT➖MSGID", "STR", "(Spoken Text)")]),

        ("direction details", MockEntry("{direction_details} for exit highway",
                                        "onto {road_number} toward {toward_name}", None, "STR", None),
         [po_to_dita.Item("{direction_details} for exit highway➖onto {road_number} toward {toward_name}", "STR",
                          "(Spoken Text) " +
                          po_to_dita.direction_details_description_template
                          % {"instruction_type": " exit", "example_msg": "'Take the exit {direction_details}.'"})]),

        ("plural, no context, msgstr plural in template is not empty",
         MockEntry(None, "MSGID", "PLURAL", "STR", ["A", "B"]),
         [po_to_dita.Item("MSGID➖PLURAL➖zero", "B", "zero"),
          po_to_dita.Item("MSGID➖PLURAL➖one", "A", "one"),
          po_to_dita.Item("MSGID➖PLURAL➖two", "B", "two"),
          po_to_dita.Item("MSGID➖PLURAL➖few", "B", "few"),
          po_to_dita.Item("MSGID➖PLURAL➖many", "B", "many"),
          po_to_dita.Item("MSGID➖PLURAL➖other", "B", "other")]),

        ("plural, context, msgstr plural in template is not empty",
         MockEntry("CONTEXT", "MSGID", "PLURAL", "", ["A", "B"]),
         [po_to_dita.Item("CONTEXT➖MSGID➖PLURAL➖zero", "B", "zero"),
          po_to_dita.Item("CONTEXT➖MSGID➖PLURAL➖one", "A", "one"),
          po_to_dita.Item("CONTEXT➖MSGID➖PLURAL➖two", "B", "two"),
          po_to_dita.Item(
              "CONTEXT➖MSGID➖PLURAL➖few", "B", "few"),
          po_to_dita.Item("CONTEXT➖MSGID➖PLURAL➖many", "B", "many"),
          po_to_dita.Item("CONTEXT➖MSGID➖PLURAL➖other", "B", "other")]),

    ])
    def test(self, _name, entry, expected_items):
        self.maxDiff = None
        actual = po_to_dita.get_data(entry)
        for actual_item, expected_item in zip(actual, expected_items):
            self.assertEqual(expected_item.id, actual_item.id)
            self.assertEqual(expected_item.text, actual_item.text)
            self.assertTrue(actual_item.description.find(expected_item.description) != -1,
                            "Can't find '" + expected_item.description + "' in '" + actual_item.description)


class TestFindAllPlaceholders(unittest.TestCase):
    @parameterized.expand([
        (
            "At the roundabout in {distance} go straight, {roundabout_exit_number} exit onto {road_number}.",
            ["{distance}", "{roundabout_exit_number}", "{road_number}"]),
        (
            "{Not_a_variable} {variable} {2_variable} {not_variable_100500} {100500_not_variable} "
            "{not_A_variable} {not_varialbe!}.",
            ["{variable}", "{2_variable}"]),
    ])
    def test(self, input_str, expected):
        actual = po_to_dita.find_all_placeholders(input_str)
        self.assertEqual(expected, actual)


if __name__ == '__main__':
    unittest.main()
