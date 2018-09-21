#!/bin/bash

CUR_DIR=$(cd "$(dirname $0)" && pwd)

cd "$CUR_DIR"


MD5="MD5 (sdkbox-appodeal_v2.4.1.1.tar.gz) = ccf0bcbada33648f1bff6baba59a7759"
ZIP_FILENAME="sdkbox-appodeal_v2.4.1.1.tar.gz"
TMP_DIR="__tmp"

if [ -f $ZIP_FILENAME ]; then
	# check zip
	CHECK_MD5=`md5 $ZIP_FILENAME`
	echo $CHECK_MD5, $MD5
	if [ "$CHECK_MD5" != "$MD5" ]; then
		echo rm $ZIP_FILENAME
		# rm $ZIP_FILENAME
	fi
fi

if [ ! -f $ZIP_FILENAME ]; then
	curl -o $ZIP_FILENAME "http://download.sdkbox.com/installer/v1/sdkbox-appodeal_v2.4.1.1.tar.gz"
fi

if [ -d $TMP_DIR ]; then
	rm -fr $TMP_DIR
fi
mkdir $TMP_DIR
cd $TMP_DIR
tar -zxvf ../$ZIP_FILENAME

IOS_FRAMEWORK="./sdkbox-appodeal_v2.4.1.1/plugin/ios/Appodeal.framework"
IOS_DEST="../build/jsb-link/frameworks/runtime-src/proj.ios_mac/Appodeal.framework"
if [ -f $IOS_DEST ]; then
    rm -rfv $IOS_DEST
fi
cp -rfv $IOS_FRAMEWORK $IOS_DEST

cd ..
rm -fr $TMP_DIR

echo ""
echo "Done."
echo ""
