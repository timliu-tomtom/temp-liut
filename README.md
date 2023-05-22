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


./Products.Android.Shared.Adaptations.AndroidJniAdaptation_command.sh
./Products.Shared.Reference.Adaptations_command.sh
./Products.Shared.Utils.project_command.sh
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
conan config install https://bitbucket.tomtomgroup.com/scm/navkit2/nk2-conan-settings.git
export NDS_DEFAULT_KEYSTORE_PASSWORD=....
export ANDROID_SDK_ROOT=~/TT/repo/AndroidSdk/
export ANDROID_SDK_ROOT=/home/liut/Android/Sdk
export ANDROID_HOME=/home/liut/Android/Sdk
export ANDROID_HOME=/home/liut/TT/repo/nk2ui/navapp-automotive/Env/Linux/Android/sdk
export JAVA_HOME=/usr/lib/jvm/java-1.11.0-openjdk-amd64

conan install -u . --install-folder=build -pr linux_x86_64-clang5
conan build . --build-folder=build
conan create -u . <version>@local/testing -pr linux_x86_64-clang5
conan export . 1.0.50@tomtom/stable
sed -i "s/#: .*\(\/navigation-instruction-text-generation.*\d\+\)/#: \/tom2\/nk2\/nk2-navigation-instruction-text-generation\1/g" "${POT_TEMPLATE_PATH}"
PROJECT_DIR=$(git rev-parse --show-toplevel); docker run --rm -it --mount type=bind,source="$PROJECT_DIR",target="$PROJECT_DIR" -w "$PROJECT_DIR" docker-navkit2.navkit-pipeline.tt3.com/tomtom/clangformat:0.2.0 run-clang-format
python3 -m pip install conan==1.46.2
```

#### NK2 dev-app ####
```
LD_LIBRARY_PATH=./lib bin/nav-engine --map ~/TT/maps/13744_icup_mg_traffic-lights_ca_points/DATA --keystore ~/TT/maps/NAVKIT_DEV.NKS --password dL8Oe.5pi9dk4- --api ... --guidance-mode onboard-v2 --mapdisplay-mode onboard 2>&1 >/dev/null | grep -e "safetylocation"
bin/nav-dimui --api ...

LD_LIBRARY_PATH=../lib ./nav-engine --api ... --map /home/ubuntu/Map/HCP3_KOR_42_20M9_ER011.1/DATA --keystore /home/ubuntu/Keystore/HCP3_DEV_NK.NKS --password dL8Oe.5pi9dk4- --mm-uri tcp://0.0.0.0:8080 --trip-uri tcp://0.0.0.0:8081 --vh-uri tcp://0.0.0.0:8082 --vehicle-uri tcp://0.0.0.0:8083 --userprofile-uri tcp://0.0.0.0:8084 --suggestions-uri tcp://0.0.0.0:8085 --datarecorder-uri tcp://0.0.0.0:8086 --rg-uri tcp://0.0.0.0:8087 --mapdisplay-uri tcp://0.0.0.0:8088 --mapdisplay-mode onboard
```


#### NK2UI ####
```
./gradlew build -PapiKey=...
./gradlew :app:assembleDebug -Pnk2ApiKey=.... --stacktrace

./gradlew :structuredSearchComponentUi:test
./gradlew :structuredSearchComponentUi:runAndroidTest

// run test in lib
./gradlew :structuredSearchComponent:test

./gradlew navigationComponentApi:ktlintFormat
./gradlew mapDisplayComponentUi:ktlintFormat

 ./gradlew mapDisplayComponentDomain:ktlintFormat mapDisplayComponent:ktlintFormat mapDisplayComponentUi:ktlintFormat mapDisplayComponentNavKit1Ui:ktlintFormat mapDisplayComponentGoSdkUi:ktlintFormat


```

#### GoSDK ####
```
./gradlew :apps:navigation-demo-app:assembleDebug
./gradlew :search:structured-search-client-api:build
./gradlew :search:structured-search-client-api:testDebugUnitTest

```

#### Azure Android ####
```
要請 Howie 加你到 resource group rg-nk1-project
https://confluence.tomtomgroup.com/display/AS/How+to+create+emulator+using+Microsoft+Azure+located+in+Korea
https://portal.azure.com/#view/HubsExtension/BrowseResource/resourceType/Microsoft.Compute%2FVirtualMachines
https://20.249.218.69/

account: geoexphela
password: geoExp!@#123
adb connect 20.249.218.69:5555
adb emu geo fix 經度 緯度
```

#### data inspector ####
```
ulimit -n 50000
```


```
wget --auth-no-challenge --user={what is user name} --ask-password --no-check-certificate https://kc-nds.tomtomgroup.com/file_download/....

wget --auth-no-challenge --user=korea --ask-password https://kc-nds.tomtomgroup.com/file_download/ccae34530160805d5528bc0c08a17984a3c2f4d9/HCP3_KOR_43_22M3_ER026.0.tar --no-check-certificate
```


#### build automotive app with local michi ####
```
cd /home/yanga/GitWorkspace/michi/michi/Build

./build.py -x Android --android-abi x86_64 -m Release --publish Local --publish-version michi-test
public to maven local
cd /home/yanga/GitWorkspace/dev-geoexpansion/SDK/ReleaseCreation

./Create_Local_AARs.py --aars michi --version michi-test --arch x86_64 --navkit-version 15.61.38 --git-repository /home/yanga/GitWorkspace/michi/

(--navkit-version 15.61.38 這個要看 /home/yanga/GitWorkspace/michi/michi/Source/navkit_version.properties 裡面的版本)
modify gradle/tt-libs.versions.toml
michi = "michi-LOCAL"
```


https://tomtomslack.slack.com/archives/G01BY3V3F6E/p1663052503821019?thread_ts=1662707261.140419&cid=G01BY3V3F6E


#### Korea server running nk1
```
How to start remote Korea server:
Local machine:
> ssh -i hela_dev_0.pem ubuntu@10.144.92.52
 Remote machine:
> cd NavKitApp/
>  export NAVKIT_REFLECTION_PORT=IP4:0.0.0.0:3000
>  ./NavKitApp.NDS
```

#### 
```
sysctl -w fs.file-max=500000

// /etc/security/limits.conf
#<domain>      <type>  <item>         <value>
*                soft   nofile          4096
*                hard   nofile          50000

// restart 
# sudo sh -c "ulimit -n 65535 && exec su $LOGNAME"
# ulimit -nh
50000

```
