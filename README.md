```
/etc/resolv.conf
/etc/init.d/networking restart
find ./* -name \*.cpp -exec grep -nH -A 3 -B 3 --color=auto "xxx" {} \;
```
#### NavKit ####
```
./build.py -f Linux-x86_64.yaml NavKitApp.FOR.NDS -m Debug -j4
./build.py -f Linux-x86_64.yaml DataAccess.Standalone.NDSMap.NDSnew.Test.ComponentTest_componenttest.FOR.NDS -m Debug -j4
./build.py -f Linux-x86_64.yaml -s Test --gtest_filter TPrecodedLocationsJapanTest.RetrieveLines --test_filters DataAccess.Standalone.NDSMap.NDSnew.Test.ComponentTest_componenttest.FOR.NDS -m Debug -j4
dependencychecker REGEN
```
#### Michi ####
```
./build.py --devenv LocalPath --devenv-root ~/TT/PSpace/michi-devenv-2
```
#### DevUI ####
```
./Build/build.py -p Linux -a x86_64 -m Debug -q /opt/apps/Qt/5.6/gcc_64/bin/qmake
./build.py -f Linux-x86_64.yaml -m Debug TestTools.DevUIPlugins -j4
```
#### NavApp ####
```
./gradlew :Products_StockNavApp:assembleDebug
./gradlew :Kits_SignatureAppKit:ktlint
./gradlew :Kits_SignatureAppKit:testDebugUnitTest --tests com.tomtom.navui.sigappkit.action.SigLowRangeStationSearchActionTest
./gradlew Products_StockNavApp:runCucumberNavigation3Test -Pscenario=FUN.NAVIGATION.ROUTE_BAR_TIMELINE.016 -PnrOfRuns=10
./gradlew Kits_SignatureViewKit:runAndroidTest -PtestClass=com.tomtom.navui.sigviewkit.test.SigFullTextSearchViewTests
./gradlew Ports_StockControl:runAndroidTest -PtestClass=com.tomtom.navui.stockcontrolport.test.LabelTests#testLabelBoundary004[HDPI-navui_SignatureControlsTheme]
adb shell am start -n com.tomtom.navui.stocknavapp/com.tomtom.navui.stocksystemport.MiniAppActivity
adb shell am broadcast -a com.tomtom.navui.debug_command --es com.tomtom.navui.debug_code "*#10038"
adb logcat -v threadtime | grep `adb shell ps | grep "com.tomtom.navui.stocknavapp" | cut -c11-15` | grep -e "TTDebug" -e "^E/" -e "System.err"
am startservice -a com.tomtom.positioning.player.START -e "log_file" "xxx.ttp"
adb shell am startservice --user 0 -n com.tomtom.navui.stocknavapp/com.tomtom.positioning.player.Player -a com.tomtom.positioning.player.START -e "log_file" "/mnt/sdcard/ttndata/smallstackedroad1_japan.ttp"
play -r 11025 -b 16 -c 1 -e signed-integer --endian little ./phonetic_blob-pcm.raw
navui-main/Kits/SignaturePromptKit/data/TomTom_cannedvoice_tool.py -c 199 ja-JP Zenrin F
```
#### QtUI ####
```
./build.py -f Linux-x86_64.yaml -m Debug
```
#### Saic2 ####
```
./gradlew :Products_AlishanApp:assembleDebug
```
#### NavCL ####
```
Build/build.py --devenv LocalPath --devenv-root ~/TT/PSpace/michi-devenv-2 -x Android -m Release --publish Local --publish-version custom-navcl-version-name
SDK/ReleaseCreation/Create_Local_AARs.py --aars navcl --version custom-navcl-version-name --arch armeabi-v7a --navkit-version navkit-version
```
#### R1 HU ####
```
su
umount /mnt/media_rw/9016-4EF8/
mount -o rw /dev/block/vold/public:8,1 /mnt/media_rw/9016-4EF8
chmod 777 /mnt/media_rw
```
#### R1 ####
```
./gradlew VehicleAdapter:testR1HighNonTargetDebugUnitTest
```
#### NK2 ####
```
export ANDROID_SDK_ROOT=~/TT/PSpace/AndroidSdk/
export JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk-amd64
./gradlew build -PapiKey=VNC4iGjGLSuJwZwNbZ2TGaCD9qzqs0Dw
conan install -u . --install-folder=build -pr linux_x86_64-clang5
conan build . --build-folder=build
conan create -u . <version>@local/testing -pr linux_x86_64-clang5
sed -i "s/#: .*\(\/navigation-instruction-text-generation.*\d\+\)/#: \/tom2\/nk2\/nk2-navigation-instruction-text-generation\1/g" "${POT_TEMPLATE_PATH}"
```
