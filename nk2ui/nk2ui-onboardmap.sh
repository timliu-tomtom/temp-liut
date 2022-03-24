adb root

#MAP_FOLDER=`adb shell ls /sdcard/maps &> /dev/null ; echo "$?"`

#if [ $MAP_FOLDER == 0 ] ; then
#  echo "has map"
#else
  echo "push map"
  adb shell rm -rf /sdcard/maps
  adb shell mkdir /sdcard/maps
  adb push ~/TT/maps/NDS_Automotive_2016.12_2.4.3_JPN_Zenrin_0318_Small_V1/* /sdcard/maps
  adb shell cp -r /sdcard/maps/* /sdcard/Android/data/com.tomtom.navkit2ui/files/map

  adb shell run-as com.tomtom.navkit2ui touch /data/data/com.tomtom.navkit2ui/files/first-run-wizard-completed
#fi


#mkdir /sdcard/maps
#rm -r /sdcard/Android/data/com.tomtom.navkit2ui/files/map/*
#adb push ~/TT/maps/NDS_Automotive_2016.12_2.4.3_JPN_Zenrin_0318_Small_V1/* /sdcard/Android/data/com.tomtom.navkit2ui/files/map
#adb push ~/TT/maps/NK_AUTO_DEV.NKS /sdcard/Android/data/com.tomtom.navkit2ui/files/keystores
#adb shell run-as com.tomtom.navkit2ui touch /data/data/com.tomtom.navkit2ui/files/first-run-wizard-completed
#adb shell ls -lah /sdcard/Android/data/com.tomtom.navkit2ui/
#adb shell chown -R u0_a142.ext_data_rw /sdcard/Android/data/com.tomtom.navkit2ui/files/
adb unroot
