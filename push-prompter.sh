#!/bin/bash


prompter_path="./prompter"
app_path="/sdcard/Android/data/com.tomtom.navapp"
app_prompter_path="/sdcard/Android/data/com.tomtom.navapp/files/app/prompter/"

adb root

####################################
echo "push Cerence tts"

adb push "$prompter_path" /sdcard/
adb shell cp -r /sdcard/prompter/* "$app_prompter_path"
adb shell rm -rf /sdcard/prompter

#####################################
echo "change permission"

owner=$(adb shell ls -lah ${app_path} | grep -e "files" | awk '{print $3}')
group=$(adb shell ls -lah ${app_path} | grep -e "files" | awk '{print $4}') 
echo "owner ${owner}, group ${group}"
adb shell chown -R ${owner}.${group} "$app_path"/files/

adb unroot


echo "finish!!!"
