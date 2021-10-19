#!/usr/bin/env bash

BUILD_DIR="build"

cpp-coveralls --gcov-options '\-lp' -b "." \
	--exclude "$BUILD_DIR/include" --exclude "$BUILD_DIR/cache/test"
