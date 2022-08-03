#!/bin/bash

LD_LIBRARY_PATH=./ ./guidance_kml_dumper \
--input /home/liut/TT/repo/nk2/nk2-navigation-instruction-engine/navigation-instruction-engine/test/regression/instruction_regression/reference/hcp3_berlin \
--recursive \
--overwrite \
--dumping_mode instruction \
--folder_id instructions_reference \
--map_path /home/liut/TT/repo/nk2/nk2-navigation-instruction-engine/build/bin/regression_test/instruction_regression/maps/hcp3_berlin/hcp3_berlin \
--keystore_path /home/liut/TT/maps/HCP3_DEV_NK.NKS \
--keystore_password dL8Oe.5pi9dk4- 2>&1 >/dev/null | grep -e "TTDebug"

LD_LIBRARY_PATH=./ ./guidance_kml_dumper \
--input /home/liut/TT/repo/nk2/nk2-navigation-instruction-engine/navigation-instruction-engine/test/regression/instruction_regression/reference/hcp3_california \
--recursive \
--overwrite \
--dumping_mode instruction \
--folder_id instructions_reference \
--map_path /home/liut/TT/repo/nk2/nk2-navigation-instruction-engine/build/bin/regression_test/instruction_regression/maps/hcp3_california/hcp3_california \
--keystore_path /home/liut/TT/maps/HCP3_DEV_NK.NKS \
--keystore_password dL8Oe.5pi9dk4- 2>&1 >/dev/null | grep -e "TTDebug" -e "side_roads_provider"


LD_LIBRARY_PATH=./ ./guidance_kml_dumper \
--input /home/liut/TT/repo/nk2/nk2-navigation-instruction-engine/navigation-instruction-engine/test/regression/instruction_regression/reference/hcp3_sanfrancisco \
--recursive \
--overwrite \
--dumping_mode instruction \
--folder_id instructions_reference \
--map_path /home/liut/TT/repo/nk2/nk2-navigation-instruction-engine/build/bin/regression_test/instruction_regression/maps/hcp3_sanfrancisco/hcp3_sanfrancisco \
--keystore_path /home/liut/TT/maps/HCP3_DEV_NK.NKS \
--keystore_password dL8Oe.5pi9dk4- \

LD_LIBRARY_PATH=./ ./guidance_kml_dumper \
--input /home/liut/TT/repo/nk2/nk2-navigation-instruction-engine/navigation-instruction-engine/test/regression/instruction_regression/reference/hcp3_uk_fra \
--recursive \
--overwrite \
--dumping_mode instruction \
--folder_id instructions_reference \
--map_path /home/liut/TT/repo/nk2/nk2-navigation-instruction-engine/build/bin/regression_test/instruction_regression/maps/hcp3_uk_fra/hcp3_uk_fra \
--keystore_path /home/liut/TT/maps/HCP3_DEV_NK.NKS \
--keystore_password dL8Oe.5pi9dk4- \

LD_LIBRARY_PATH=./ ./guidance_kml_dumper \
--input /home/liut/TT/repo/nk2/nk2-navigation-instruction-engine/navigation-instruction-engine/test/regression/instruction_regression/reference/tt_nl_ger_north \
--recursive \
--overwrite \
--dumping_mode instruction \
--folder_id instructions_reference \
--map_path /home/liut/TT/repo/nk2/nk2-navigation-instruction-engine/build/bin/regression_test/instruction_regression/maps/tt_nl_ger_north/tt_nl_ger_north \
--keystore_path /home/liut/TT/maps/NK_AUTO_DEV.NKS \
--keystore_password dL8Oe.5pi9dk4-


## 382-395
# 4/12 submit back