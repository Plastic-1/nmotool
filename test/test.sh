#! /bin/bash
COUNT=1

SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
RESULT_DIR=$SCRIPT_DIR/results
mkdir -p $RESULT_DIR

OTOOL=$SCRIPT_DIR/../ft_otool
NM=$SCRIPT_DIR/../ft_nm

TEST_FILES="$SCRIPT_DIR/../objects/**/* "
TEST_FILES="$SCRIPT_DIR/../objects/* "
TEST_FILES+="/usr/lib/* "
TEST_FILES+="/usr/bin/* "
TEST_FILES+="/bin/* "

for FILE in `ls $TEST_FILES`
do
	$OTOOL -td -arch x86_64 -arch i386 -s __TEXT __const $FILE > "$RESULT_DIR/$COUNT-ot-a" 2> /dev/null
	otool -td -arch x86_64 -arch i386 -s __TEXT __const $FILE > "$RESULT_DIR/$COUNT-ot-b" 2> /dev/null
	DIF_OT=$( diff "$RESULT_DIR/$COUNT-ot-a" "$RESULT_DIR/$COUNT-ot-b" )
	if [ -n "$DIF_OT" ]
	then
		echo "Diff otool for $FILE ($COUNT-ot-a / $COUNT-ot-b):"
		echo -e "$DIF_OT"
		echo -e "\n==========================================\n"
	fi

	$NM  $FILE > "$RESULT_DIR/$COUNT-nm-a" 2> /dev/null
	nm $FILE > "$RESULT_DIR/$COUNT-nm-b" 2> /dev/null
	DIF_NM=$( diff "$RESULT_DIR/$COUNT-nm-a" "$RESULT_DIR/$COUNT-nm-b" )
	if [ -n "$DIF_NM" ]
	then
		echo "Diff nm for $FILE ($COUNT-nm-a / $COUNT-nm-b):"
		echo -e "$DIF_NM"
		echo -e "\n==========================================\n"
	fi

	COUNT=$(($COUNT+1))
done
