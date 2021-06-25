#!/usr/bin/env python3

import re
import os
import sys
import glob
import argparse

sourceDir = "src"
description="Checks and report's functions that are missing quick info"

argParser = argparse.ArgumentParser(description=description, formatter_class=argparse.ArgumentDefaultsHelpFormatter)
argParser.add_argument("directory", nargs="?", default=sourceDir, type=str,
	help=f"directory to search")

args = argParser.parse_args()
sourceDir = args.directory

# --- Change dir to project root
targetPath = os.path.dirname(sys.path[0]) # Removes '/tools' from the end
os.chdir(targetPath)

# --- Check if sourceDir exists
if not os.path.exists(sourceDir):
	print(f"Error: The directory '{sourceDir}' doesn't exist")
	exit(1)

# --- Search for missing quick info
noQuickInfoRegex = r"^(?!\/\*\n(\*{2}.*?\n)*\*\/)\n(?!\bstatic\b)(\b.*?\n?\()"
globPattern = os.path.join(sourceDir, "**/*.c")
for file in glob.glob(globPattern, recursive=True):
	if file.endswith("_test.c"): # Exclude test files
		continue

	try:
		with open(file, "r") as fd:
			content = fd.read()
		regexMataches = re.findall(noQuickInfoRegex, content, flags=re.MULTILINE)
		if regexMataches == None:
			continue
		for match in regexMataches:
			functionName = match[1].split()[-1] # Select function name
			functionName = functionName[functionName.count("*"):-1] # Trim off '*' and '('
			print(f"Warning: Function '{functionName}' missing quick info in '{file}'")
	except:
		print(f"Error: Checking quickInfo of file '{file}'")
