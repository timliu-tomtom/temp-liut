#!/bin/bash


#############################################################################################
# 1. install app-navkit1-debug.apk or app-navkit2-debug.apk
# 2. run app first to let app folder /sdcard/Android/data/com.tomtom.navapp.xxxxx created
# 3. close app
# 4. go to android system setting -> application -> navapp -> grant all permission
# 5. run this script e.g. ./nk2ui_onboardmap.sh -s small -n nk1 , for installing small Japan map for nk1
# 6. run app, if nk2 need to change configuration to onboard (configuration_A) and again restart


help_function()
{
  echo "-s: map to push, options are small or large, default small"
  echo "-n: automotive-nk1, automotive-gosdk or gosdk (navigation-demo-app)"
  echo "usage: ./nk2ui_onboardmap.sh -s [small|full] -n [automotive-nk1|automotive-gosdk|gosdk]"
  exit 1
}

while getopts "s:n:" opt
do
  case "$opt" in 
	  s ) map_option="$OPTARG" ;;
	  n ) nk_option="$OPTARG" ;;
	  ? ) help_function ;;	  
  esac
done


################################
# Change map and keystore here #
################################
if [ -z "$map_option" ] || [ "$map_option" == "small" ]
then
  map_path="/home/liut/TT/maps/NDS_Automotive_2016.12_2.4.3_JPN_Zenrin_0318_Small_V1"
  keystore_path="/home/liut/TT/maps/NK_AUTO_DEV.NKS"
elif [ "$map_option" == "bundled" ]
then 
  map_path="/home/liut/TT/maps/bundled"
  keystore_path="/home/liut/TT/maps/NK_AUTO_DEV_bundled.NKS"
elif [ "$map_option" == "hcp3_tw" ]
then
  map_path="/home/liut/TT/maps/HCP3_TWN_43_211E0_ER029.1/HCP3_TWN_43_211E0_ER029.1/DATA"
  keystore_path="/home/liut/TT/maps/HCP3_DEV_NK.NKS"
elif [ "$map_option" == "hcp3_ko" ]
then
  map_path="/home/liut/TT/maps/HCP3_KOR_43_22M3_ER026.0/HCP3_KOR_43_22M3_ER026.0/DATA"
  keystore_path="/home/liut/TT/maps/HCP3_DEV_NK.NKS"
elif [ "$map_option" == "42296" ]
then
  map_path="/home/liut/TT/maps/42296_NDS_AutomotiveReference_2021.06_2.4.6_KOR_IQ/DATA"
  keystore_path="/home/liut/TT/maps/NK_AUTO_DEV.NKS"
elif [ "$map_option" == "fisker_tw" ]
then
  map_path="/home/liut/TT/maps/NDS_SelfService_2021.12.000_2.4.6_TWN_Fisker_b211/DATA"  
  keystore_path="/home/liut/TT/maps/NK_AUTO_DEV.NKS"
elif [ "$map_option" == "bmw_44502" ]
then
  map_path="/home/liut/TT/maps/44502_NDS_BMW_Motorrad_2021.12_2.4.6_JPN_1222_Sample_V1_WOM/DATA"
  keystore_path="/home/liut/TT/maps/NK_BMW_1.NKS"
elif [ "$map_option" == "bmw_44891" ]
then
  map_path="/home/liut/TT/maps/44891_NDS_AutomotiveReference_2023.03.000_2.4.6_KOR-BMW/NDS_AutomotiveReference_2023.03.000_2.4.6_KOR-BMW/DATA"
  keystore_path="/home/liut/TT/maps/NK_BMW_1.NKS"
elif [ "$map_option" == "hcp3_small" ]
then
  map_path="/home/liut/TT/maps/JPN_44_22R1_DD130/DATA"
  keystore_path="/home/liut/TT/maps/HCP3_DEV_NK.NKS"
else
  map_path="/home/liut//TT/maps/NDS_Automotive_2020.06_2.4.6_JPN_1120_V1/DATA"
  keystore_path="/home/liut/TT/maps/NK_AUTO_DEV.NKS"
fi


if [ -z "$nk_option" ] || [ "$nk_option" == "gosdk" ] 
then
  nk_option="gosdk"
  app_path="/sdcard/Android/data/com.tomtom.sdk.navigation.examples"
  app_map_path="/sdcard/Android/data/com.tomtom.sdk.navigation.examples/files/offline/map"
  app_keystore_path="/sdcard/Android/data/com.tomtom.sdk.navigation.examples/files/offline/keystore.sqlite"
elif [ "$nk_option" == "gosdk-map" ]
then
  nk_option="gosdk-map"
  app_path="/sdcard/Android/data/com.tomtom.sdk.map.display.examples"
  app_map_path="/sdcard/Android/data/com.tomtom.sdk.map.display.examples/files/offline/map"
  app_keystore_path="/sdcard/Android/data/com.tomtom.sdk.map.display.examples/files/offline/keystore.sqlite"
elif [ "$nk_option" == "automotive-gosdk" ]
then
  nk_option="automotive-gosdk"
  app_path="/sdcard/Android/data/com.tomtom.navapp.gosdk"
  app_map_path="/sdcard/Android/data/com.tomtom.navapp.gosdk/files/maps/bundled"
  app_keystore_path="/sdcard/Android/data/com.tomtom.navapp.gosdk/files/keystores/NK_AUTO_DEV.NKS"
else
  nk_option="automotive-nk1"
  app_path="/sdcard/Android/data/com.tomtom.navapp"
  app_map_path="/sdcard/Android/data/com.tomtom.navapp/files/maps/bundled"
  app_keystore_path="/sdcard/Android/data/com.tomtom.navapp/files/keystores/NK_AUTO_DEV.NKS"
fi


echo "push ${map_path} for ${nk_option}"

#adb root


####################################
echo "push map"
  
if [ "$nk_option" == "gosdk" ]
then
  adb shell mkdir "/sdcard/Android/data/com.tomtom.sdk.navigation.examples/files/offline"
  adb shell mkdir "/sdcard/Android/data/com.tomtom.sdk.navigation.examples/files/offline/map"
elif [ "$nk_option" == "gosdk-map" ]
then
  adb shell mkdir "/sdcard/Android/data/com.tomtom.sdk.map.display.examples/files/offline"
  adb shell mkdir "/sdcard/Android/data/com.tomtom.sdk.map.display.examples/files/offline/map"
fi

adb shell rm -rf /sdcard/map

adb shell mkdir /sdcard/map
adb push "$map_path"/* /sdcard/map
adb shell rm -rf "$app_map_path"/*
adb shell cp -r /sdcard/map/* "$app_map_path"

adb shell rm -rf /sdcard/map



######################################
echo "push keystore"

adb shell rm -rf /sdcard/keystore

adb shell mkdir /sdcard/keystore
adb push "$keystore_path" /sdcard/keystore/keystore.sqlite
adb shell cp /sdcard/keystore/keystore.sqlite "$app_keystore_path"

adb shell rm -rf /sdcard/keystore



###################################
#if [ "$nk_option" == "nk2" ]
#then
#  echo "nk2 skip first wizard"
#  adb shell run-as com.tomtom.navapp touch /data/data/com.tomtom.navapp/files/first-run-wizard-completed
#fi


#####################################
echo "change permission"
adb shell chmod 777 -R "$app_map_path"
adb shell chmod 777 -R "$app_keystore_path"

#owner=$(adb shell ls -lah ${app_path} | grep -e "files" | awk '{print $3}')
#group=$(adb shell ls -lah ${app_path} | grep -e "files" | awk '{print $4}') 
#echo "owner ${owner}, group ${group}"
#adb shell chown -R ${owner}.${group} "$app_path"/files/

#adb unroot


echo "finish!!!"
