<!--
Copyright (C) 1992 TomTom NV. All rights reserved.

This software is the proprietary copyright of TomTom NV and its subsidiaries and may be
used for internal evaluation purposes or commercial use strictly subject to separate
license agreement between you and TomTom NV. If you are the licensee, you are only permitted
to use this software in accordance with the terms of your license agreement. If you are
not the licensee, you are not authorized to use this software in any manner and should
immediately return or destroy it.
-->

# Conversion script between PO and LOC XML
## Background
https://jira.tomtomgroup.com/browse/NAV-57700  
Conversion PO->WorldServer XML https://jira.tomtomgroup.com/browse/NAV-68118

## Run without PyCharm
```
$./po-dita-converter.sh args...
```

DITA v 1.1 Spec. xsd: https://docs.oasis-open.org/dita/v1.1/OS/archspec/archspec.html#schemaorganization
DITA for the Impatient: https://www.xmlmind.com/tutorials/DITA/index.html


## Debugging tests with PyCharm

Add Plugin for pytest to enter PyCharm debugger on uncaught exceptions from:  
https://github.com/jlubcke/pytest-pycharm  
By (temporarily) adding `pytest-pycharm~=0.7.0` to the `requirements.txt`.  
Or running `pip install pytest-pycharm` in the venv directly.

In addition, enable: `Drop into debugger on failed tests` in the PyCharm settings.  
src: https://www.jetbrains.com/help/pycharm/rerunning-tests.html#debug-tests
