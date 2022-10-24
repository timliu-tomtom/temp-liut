# Copyright (C) 2022 TomTom NV. All rights reserved.
#
# This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
# used for internal evaluation purposes or commercial use strictly subject to separate
# license agreement between you and TomTom NV. If you are the licensee, you are only permitted
# to use this software in accordance with the terms of your license agreement. If you are
# not the licensee, you are not authorized to use this software in any manner and should
# immediately return or destroy it.

project(instruction_regression_test)

set(VENV_DIR ${CMAKE_CURRENT_BINARY_DIR}/venv)
set(VENV_PYTHON ${VENV_DIR}/bin/python3)

execute_process(COMMAND python3 -m venv "${VENV_DIR}" RESULT_VARIABLE script_result)

if(NOT "${script_result}" STREQUAL 0)
    message(FATAL_ERROR "Failed to install venv. Script result: ${script_result}")
endif()

execute_process(COMMAND "${VENV_PYTHON}" -m pip install -r ${CMAKE_CURRENT_SOURCE_DIR}/requirements.txt --index-url https://artifactory.navkit-pipeline.tt3.com/artifactory/api/pypi/pypi-virtual/simple
        RESULT_VARIABLE script_result)
if(NOT "${script_result}" STREQUAL 0)
    message(FATAL_ERROR "Failed to install python dependencies. Script result: ${script_result}")
endif()

enable_testing()

add_test(NAME po_dita_converter_test
        COMMAND bash "-c" ". ${VENV_DIR}/bin/activate && python3 -m unittest -v ${CMAKE_CURRENT_SOURCE_DIR}/tests/convert_po_to_dita_test.py"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_test(NAME dita_po_converter_test
        COMMAND bash "-c" ". ${VENV_DIR}/bin/activate && python3 -m unittest -v ${CMAKE_CURRENT_SOURCE_DIR}/tests/convert_dita_to_po_test.py"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

set_tests_properties(po_dita_converter_test PROPERTIES TIMEOUT 60)
