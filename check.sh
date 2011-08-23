TEMP_FILE=result-$$.txt
./stac.sh > $TEMP_FILE
diff ok.txt $TEMP_FILE
if [ $? = 0 ]; then
    echo OK
else
    echo NG
fi
rm $TEMP_FILE

TEMP_FILE=result-$$.txt
./binary_text test.bin $TEMP_FILE
diff test.txt $TEMP_FILE
if [ $? = 0 ]; then
    echo OK
else
    echo NG
fi
rm $TEMP_FILE
