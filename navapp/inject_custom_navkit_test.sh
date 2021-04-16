#!/bin/bash

# Change to your home directory
HOME_DIR=/home/liut/TT/PSpace/inject_custom_navkit

JARS_DIR=${HOME_DIR}/bin
APKTOOL_JAR_NAME=apktool_2.3.0.jar
APKTOOL_JAR=${HOME_DIR}/bin/${APKTOOL_JAR_NAME}
UBER_APK_SIGNER_JAR_NAME=uber-apk-signer-0.8.1.jar
UBER_APK_SIGNER_JAR=${HOME_DIR}/bin/${UBER_APK_SIGNER_JAR_NAME}

CHINA_STYLE_DIR=${HOME_DIR}/ChinaStyle-2994127

# Change to your Desktop directory
DESKTOP_DIR=${HOME_DIR}/

TMP_DIR=${DESKTOP_DIR}/tmp
OUTPUT_DIR=${DESKTOP_DIR}/injectOutput

UPDATE_FROM_NAVKIT_APK=false
COPY_CHINA_STYLE=false

NAVAPP_APK_NAME=Products_StockNavApp-debug

REFERENCE_NAVKIT_APK_NAME=NavKitService.NDS-release
REFERENCE_NAVKIT_APK=${DESKTOP_DIR}/${REFERENCE_NAVKIT_APK_NAME}.apk
REFERENCE_MAPVIEWER_SO_NAME=libMapViewer2
REFERENCE_MAPVIEWER_SO=${DESKTOP_DIR}/${REFERENCE_MAPVIEWER_SO_NAME}.so

echo "Preparing tools"
if [ ! -d ${JARS_DIR} ]; then
    mkdir -p ${JARS_DIR}
fi

if [ ! -f ${APKTOOL_JAR} ]; then
    echo "Downloading ${APKTOOL_JAR_NAME}"
    wget -P ${JARS_DIR} "https://bitbucket.org/iBotPeaches/apktool/downloads/${APKTOOL_JAR_NAME}"
fi

if [ ! -f ${UBER_APK_SIGNER_JAR} ]; then
    echo "Downloading ${UBER_APK_SIGNER_JAR_NAME}"
    wget -P ${JARS_DIR} "https://github.com/patrickfav/uber-apk-signer/releases/download/v0.8.1/${UBER_APK_SIGNER_JAR_NAME}"
fi

#for DIR in ${TMP_DIR} ${OUTPUT_DIR}; do
#    if [ -d "${DIR}" ]; then
#        echo  "Removing '${DIR}' dir"
#        rm -rf ${DIR}
#    fi
#    mkdir ${DIR}
#done

#echo "Unpacking ${NAVAPP_APK_NAME}"
#cp ${HOME_DIR}/${NAVAPP_APK_NAME}.apk ${TMP_DIR}
#java -jar ${APKTOOL_JAR} d -s -r ${TMP_DIR}/${NAVAPP_APK_NAME}.apk -o ${TMP_DIR}/${NAVAPP_APK_NAME}

#cp ${HOME_DIR}/libShiftingd.so ${TMP_DIR}/${NAVAPP_APK_NAME}/lib/armeabi-v7a
#chmod +x ${TMP_DIR}/${NAVAPP_APK_NAME}/lib/armeabi-v7a/libShiftingd.so

if [ "${UPDATE_FROM_NAVKIT_APK}" = true ]; then
    echo "Unpacking ${REFERENCE_NAVKIT_APK_NAME} to get additional .so files"
    cp ${REFERENCE_NAVKIT_APK} ${TMP_DIR} || { echo "Failed to copy ${REFERENCE_NAVKIT_APK}" ; exit 1; }
    java -jar ${APKTOOL_JAR} d ${TMP_DIR}/${REFERENCE_NAVKIT_APK_NAME}.apk -o ${TMP_DIR}/${REFERENCE_NAVKIT_APK_NAME}

    echo "Copying .so files from ${REFERENCE_NAVKIT_APK_NAME} to ${NAVAPP_APK_NAME}"
    cp -fv ${TMP_DIR}/${REFERENCE_NAVKIT_APK_NAME}/lib/armeabi-v7a/* ${TMP_DIR}/${NAVAPP_APK_NAME}/lib/armeabi-v7a || { echo "Failed to copy .so files" ; exit 1; }
fi

if [ "${COPY_CHINA_STYLE}" = true ]; then
    echo "Copying China style from ${MICHI_DIR}"
    cp -fv ${CHINA_STYLE_DIR}/china.json ${TMP_DIR}/${NAVAPP_APK_NAME}/assets/default.json || { echo "Failed to copy json file" ; exit 1; }

    echo "Copying city node icon from ${MICHI_DIR}"
    cp -rfv ${CHINA_STYLE_DIR}/Icons/hdpi/city-node ${TMP_DIR}/${NAVAPP_APK_NAME}/assets/icons-hdpi || { echo "Failed to copy hdpi icon" ; exit 1; }
    cp -rfv ${CHINA_STYLE_DIR}/Icons/ldpi/city-node ${TMP_DIR}/${NAVAPP_APK_NAME}/assets/icons-ldpi || { echo "Failed to copy ldpi icon" ; exit 1; }
    cp -rfv ${CHINA_STYLE_DIR}/Icons/mdpi/city-node ${TMP_DIR}/${NAVAPP_APK_NAME}/assets/icons-mdpi || { echo "Failed to copy mdpi icon" ; exit 1; }
    cp -rfv ${CHINA_STYLE_DIR}/Icons/xhdpi/city-node ${TMP_DIR}/${NAVAPP_APK_NAME}/assets/icons-xhdpi || { echo "Failed to copy xhdpi icon" ; exit 1; }
    cp -rfv ${CHINA_STYLE_DIR}/Icons/xxhdpi/city-node ${TMP_DIR}/${NAVAPP_APK_NAME}/assets/icons-xxhdpi || { echo "Failed to copy xxhdpi icon" ; exit 1; }
    cp -rfv ${CHINA_STYLE_DIR}/Icons/xxxhdpi/city-node ${TMP_DIR}/${NAVAPP_APK_NAME}/assets/icons-xxxhdpi || { echo "Failed to copy xxxhdpi icon" ; exit 1; }
fi

echo "Packing and signing ${NAVAPP_APK_NAME}"
java -jar ${APKTOOL_JAR} b ${TMP_DIR}/${NAVAPP_APK_NAME}
java -jar ${UBER_APK_SIGNER_JAR} -a ${TMP_DIR}/${NAVAPP_APK_NAME}/dist/${NAVAPP_APK_NAME}.apk --allowResign -o ${OUTPUT_DIR}
echo "Done packing and signing ${NAVAPP_APK_NAME}"


