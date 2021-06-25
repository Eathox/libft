#!/usr/bin/env bash

NORM_DIR="norm"
BUILD_DIR="build"

cpp-coveralls --gcov-options '\-lp' -b "." --exclude "$NORM_DIR" \
	--exclude "$BUILD_DIR/include" --exclude "$BUILD_DIR/cache/test"
