#!/usr/bin/env python3

import re
import os
import sys
import glob
import argparse

fileExt = ".h"
sourceDir = "modules"
description="Checks and report's functions that are missing docInfo"

argParser = argparse.ArgumentParser(description=description, formatter_class=argparse.ArgumentDefaultsHelpFormatter)
argParser.add_argument("directory", nargs="?", default=sourceDir, type=str,
	help=f"directory to search")
argParser.add_argument("-x", "--ext", dest="fileExt", default=fileExt, type=str,
	help=f"file extension to match")

args = argParser.parse_args()
sourceDir = args.directory
fileExt = args.fileExt

# --- Change dir to project root
targetPath = os.path.dirname(sys.path[0]) # Removes '/tools' from the end
os.chdir(targetPath)

# --- Check if sourceDir exists
if not os.path.exists(sourceDir):
	print(f"Error: The directory '{sourceDir}' doesn't exist")
	exit(1)

# --- Function for getting functionName out of a regex match
def matchToFunctionName(match: str) -> str:
	functionName = match[1].split()[-1] # Select function name
	functionName = functionName[functionName.count("*"):-1] # Trim off '*' and '('
	return functionName

# --- Search for missing docInfo
noDocInfoRegex = r"^(?!\/\*\n(\*{2}.*?\n)*\*\/)\n(?!\bstatic\b)(\b.*?\n?\()"
globPattern = os.path.join(sourceDir, "**/*" + fileExt)
for file in glob.glob(globPattern, recursive=True):
	if file.endswith("_test.c"): # Exclude test files
		continue

	try:
		with open(file, "r") as fd:
			content = fd.read()
		regexMatches = re.findall(noDocInfoRegex, content, flags=re.MULTILINE)
		if regexMatches == None:
			continue

		functionsMissionInfo = list(map(matchToFunctionName, regexMatches))
		if len(functionsMissionInfo) == 0:
			continue

		print(f"Missing docInfo in '{file}'")
		for functionName in functionsMissionInfo:
			print(f"- {functionName}")
	except Exception:
		print(f"Error: Checking docInfo of file '{file}'")
