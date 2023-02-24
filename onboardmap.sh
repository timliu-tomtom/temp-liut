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
elif [ "$map_option" == "tw" ]
then
  map_path="/home/liut/TT/maps/NDS_AutomotiveReference_2017.03_2.4.3_TWN_jv_test/DATA"
  keystore_path="/home/liut/TT/maps/NAVKIT_DEV.NKS"
elif [ "$map_option" == "bmw" ]
then
  map_path="/home/liut/TT/maps/NDS_BMW_Motorrad_2021.12_2.4.6_JPN_1222_Sample_V1_WOM/DATA"
  keystore_path="/home/liut/TT/maps/NK_BMW_1.NKS"
else
  map_path="/home/liut//TT/maps/NDS_Automotive_2020.06_2.4.6_JPN_1120_V1/DATA"
  keystore_path="/home/liut/TT/maps/NK_AUTO_DEV.NKS"
fi


if [ -z "$nk_option" ] || [ "$nk_option" == "gosdk" ] 
then
  nk_option="gosdk"
  app_path="/sdcard/Android/data/com.tomtom.sdk.navigation.examples"
  app_map_path="/sdcard/Android/data/com.tomtom.sdk.navigation.examples/files/onboard/map"
  app_keystore_path="/sdcard/Android/data/com.tomtom.sdk.navigation.examples/files/onboard/keystore.sqlite"
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
  adb shell mkdir "/sdcard/Android/data/com.tomtom.sdk.navigation.examples/files/onboard"
  adb shell mkdir "/sdcard/Android/data/com.tomtom.sdk.navigation.examples/files/onboard/map"
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
