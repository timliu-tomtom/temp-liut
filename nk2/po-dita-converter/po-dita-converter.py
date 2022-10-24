#!/usr/bin/env python3

# Copyright (C) 2021 TomTom NV. All rights reserved.
#
# This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
# used for internal evaluation purposes or commercial use strictly subject to separate
# license agreement between you and TomTom NV. If you are the licensee, you are only permitted
# to use this software in accordance with the terms of your license agreement. If you are
# not the licensee, you are not authorized to use this software in any manner and should
# immediately return or destroy it.

""" PO - DITA Converter

Usage:
  po-dita-converter po2dita <template> <output>
  po-dita-converter dita2po <input> <output>
  po-dita-converter validate <input>
  po-dita-converter (-h | --help)
  po-dita-converter --version
  po-dita-converter

Commands:
  po2dita              to convert from po to dita file
  dita2po              to convert from dita to po file
  validate             check if file has valid xml schema

Options:
  -h --help            Show this screen.
  --version            Show version.
  template             file used for en-GB template strings
  input                path to xml file
  output               path to po file
"""

# build in
import sys

# extern
from docopt import docopt
from lxml import etree

# internal
import src.convert_po_to_dita as po_to_dita
import src.convert_dita_to_po as dita_to_po


def validate_schema(xml_path: str, xsd_path: str) -> bool:
    """
    Validates xml document using a provided xsd.
    Returns 'true' if validation passed successfully, otherwise 'false'
    """
    xml_schema_doc = etree.parse(xsd_path)
    xml_schema = etree.XMLSchema(xml_schema_doc)
    xml_doc = etree.parse(xml_path)
    result = xml_schema.validate(xml_doc)
    xml_parser = etree.XMLParser(schema=xml_schema)
    # this throws if schema is not followed, so get an error message with the issue
    if not result:
        try:
            etree.parse(xml_path, xml_parser)
        except Exception as err:
            print('Validation failed: {0}'.format(err))

    return result


def main(args):
    print('args input:\n', args)

    if args['validate']:
        is_valid_schema = validate_schema(args['<input>'], 'res/schema.xsd')
        if not is_valid_schema:
            sys.exit(1)
        else:
            print('Validation passed.')

    if args['po2dita']:
        po_to_dita.convert_po_to_dita(
            args['<template>'], args['<output>'])
        is_valid_schema = validate_schema(args['<output>'], 'res/schema.xsd')
        if not is_valid_schema:
            sys.exit(1)

    if args['dita2po']:
        dita_to_po.convert_dita_to_po(args['<input>'], args['<output>'])


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # execute only if run as a script
    main(docopt(__doc__, version='0.0.1'))
