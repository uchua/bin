#!/bin/bash

SEARCH_DIR="";

ERR_FLAG_INV_DIR=false;

if [ $# -eq 1 ]; then
	# Look in current working directory
	SEARCH_DIR="$PWD";
elif [ $# -eq 2 ]; then
	# Look in specified target directory
	if [ -d "$2" ]; then
		SEARCH_DIR="$2";
	else
		ERR_FLAG_INV_DIR=true;
	fi
fi

if [ ! -z "$SEARCH_DIR" ]; then
	echo "Searching $SEARCH_DIR...";
	for f in $SEARCH_DIR/*
	do
		f_out="";
		if [ ! -d "$f" ]; then
			f_out="$(cat $f | grep $1)";
		fi
		if [ ! -z "$f_out" ]; then
			echo "File: $f";
			echo "Found:";
			echo "${f_out}";
		fi
	done
else
	if [ $ERR_FLAG_INV_DIR == true ]; then
		echo "Error: Invalid target search directory";
	fi
	echo "Usage: $0 SEARCH_STRING [TARGET_DIRECTORY]";
fi
