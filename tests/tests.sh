#!/bin/bash
SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
RESULT_DIR=$SCRIPT_DIR/results
TMP_DIR=$SCRIPT_DIR/tmp
mkdir -p $RESULT_DIR
mkdir -p $TMP_DIR

TEST_DIRS="$SCRIPT_DIR/../objects "
TEST_DIRS+="/usr/lib "
TEST_DIRS+="/usr/bin "
TEST_DIRS+="/bin "

TEST_FILES=`find $TEST_DIRS -type f`


#Tests otool
OTOOL=$SCRIPT_DIR/../ft_otool
COUNT=1

FLAGS_LIST=(
	'-t'
	'-t -arch i386'
	'-t -arch x86_64'
	'-t -arch i386 -arch x86_64'
	'-d'
	'-d -arch i386'
	'-s __DATA __data -arch i386 -arch x86_64'
	'-s __DATA __dyld'
)

for FLAGS in "${FLAGS_LIST[@]}"
do
	RESULT_FILE=$RESULT_DIR/otool-$COUNT
	touch $RESULT_FILE
	for FILE in $TEST_FILES
	do
		$OTOOL $FLAGS $FILE > "$TMP_DIR/otool-a" 2> /dev/null
		otool $FLAGS $FILE > "$TMP_DIR/otool-b" 2> /dev/null
		DIF_OTOOL=$(diff "$TMP_DIR/otool-a" "$TMP_DIR/otool-b")
		if [ -n "$DIF_OTOOL" ]
		then
			echo "Diff on: otool $FLAGS $FILE" >> $RESULT_FILE
			file $FILE >> $RESULT_FILE
			echo -e "$DIF_OTOOL" >> $RESULT_FILE
			echo -e "\n==========================================\n" >> $RESULT_FILE
		fi
	done
	echo "Test otool $COUNT/${#FLAGS_LIST[@]} done"
	COUNT=$(($COUNT+1))
done


#Tests nm
NM=$SCRIPT_DIR/../ft_nm
COUNT=1

FLAGS_LIST=(
	''
	'-arch i386'
	'-arch x86_64'
	'-r -arch i386'
	'-r'
	'-pu'
	'-jU'
	'-g'
)

for FLAGS in "${FLAGS_LIST[@]}"
do
	RESULT_FILE=$RESULT_DIR/nm-$COUNT
	touch $RESULT_FILE
	for FILE in `ls $TEST_FILES`
	do
		$NM $FLAGS $FILE > "$TMP_DIR/nm-a" 2> /dev/null
		nm $FLAGS $FILE > "$TMP_DIR/nm-b" 2> /dev/null
		DIF_NM=$(diff "$TMP_DIR/nm-a" "$TMP_DIR/nm-b")
		if [ -n "$DIF_NM" ]
		then
			echo "Diff on: nm $FLAGS $FILE" >> $RESULT_FILE
			file $FILE >> $RESULT_FILE
			echo -e "$DIF_NM" >> $RESULT_FILE
			echo -e "\n==========================================\n" >> $RESULT_FILE
		fi
	done
	echo "Test nm $COUNT/${#FLAGS_LIST[@]} done"
	COUNT=$(($COUNT+1))
done
