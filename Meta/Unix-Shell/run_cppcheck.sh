#!/usr/bin/bash

if [ ! "$(command -v cppcheck)" ]; then
	echo "\033[41;37m Warning: Cppcheck not found in your pc, please install this \033[0m \n"
	exit 0
fi

SRC_DIRECTORY="Src"
INCLUDE_DIRECTORY="Include"

SRC_LIST=$(find "$SRC_DIRECTORY" -name "*.cpp" -name "*.c")

if [ -z "$SRC_LIST" ]; then
	printf "\033[41;37m Warning: No .c / .cpp files found in $SRC_DIRECTORY \033[0m \n"
	exit 0
fi

cppcheck "$SRC_LIST" \
	-I "$INCLUDE_DIRECTORY" \
	--enable=warning \
	--enable=style \
	--enable=performance \
	--enable=information \
	--check-config \
	--inconclusive \
	--suppress=missingInclude

