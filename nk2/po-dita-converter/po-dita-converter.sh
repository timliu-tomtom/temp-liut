#!/bin/bash

# Copyright (C) 2021 TomTom NV. All rights reserved.
#
# This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
# used for internal evaluation purposes or commercial use strictly subject to separate
# license agreement between you and TomTom NV. If you are the licensee, you are only permitted
# to use this software in accordance with the terms of your license agreement. If you are
# not the licensee, you are not authorized to use this software in any manner and should
# immediately return or destroy it.

function update_venv(){
  local PYPI_INDEX='https://artifactory.navkit-pipeline.tt3.com/artifactory/api/pypi/pypi-virtual/simple'
  pip3 install --upgrade pip
  pip3 install --upgrade --index-url ${PYPI_INDEX} -r requirements.txt
}

function activate_venv(){
  local SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
  local VENV="$SCRIPTPATH/venv"

  set -e
  if [[ ! -d "${VENV}" ]] ; then
    python3 -m venv "${VENV}"
    source "${VENV}/bin/activate"
    update_venv #upgrade, if needed
  else
    source "${VENV}/bin/activate"
  fi
  set +e
}

function run_with_venv() {
  activate_venv
  python3 "$@"
  deactivate
}

run_with_venv generate-jira-trans.py "$@"