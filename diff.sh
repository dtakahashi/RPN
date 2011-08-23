#echo $#
V=0
if [ $# == 2 ]; then
    V=1
    shift
fi

if [ $# != 1 ]; then
    echo Usage diff_test file
    exit
fi
FILE=$1
echo $FILE
if [ ! -e $FILE ]; then
    echo not exist $FILE
    exit
fi

if [ $V = 1 ]; then
    echo ----------------------
    cat $FILE
    echo -----------------------
fi

FILE_BIN=file_bin_$$
FILE_SCRIPT=file_script_$$

echo ./text $FILE $FILE_BIN
./text $FILE $FILE_BIN

echo ./binary_text $FILE_BIN $FILE_SCRIPT
./binary_text $FILE_BIN $FILE_SCRIPT

diff $FILE $FILE_SCRIPT
if [ $? = 0 ]; then
    echo OK
else
    echo ******************NG
fi

rm $FILE_BIN $FILE_SCRIPT
