TEMP_FILE=result-$$.txt
./img.sh > $TEMP_FILE
diff okimg.txt $TEMP_FILE
if [ $? = 0 ]; then
    echo OK
else
    echo NG
fi
rm $TEMP_FILE

TEMP_FILE=result-$$.txt
./binary_text img.bin $TEMP_FILE
diff img.txt $TEMP_FILE
if [ $? = 0 ]; then
    echo OK
else
    echo NG
fi
rm $TEMP_FILE
