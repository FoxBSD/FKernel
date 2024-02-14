#!/usr/bin/bash

if [ ! "$(command -v cppcheck)" ]; then
	echo "Cppcheck not found in your pc, please install this"
	exit 0
fi

CPP_DIRECTORY="Src"
HPP_DIRECTORY="Include"

CPP_LIST=$(find "$CPP_DIRECTORY" -name "*.cpp")

if [ -z "$CPP_LIST" ]; then
	echo "No .cpp files found in $CPP_DIRECTORY"
	exit 0
fi

cppcheck "$CPP_LIST" \
	-I "$HPP_DIRECTORY" \
	--enable=warning \
	--enable=style \
	--enable=performance \
	--enable=information \
	--check-config \
	--inconclusive \
	--suppress=missingInclude

