#!/usr/bin/env python3
# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    quickInfo.py                                       :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/25 19:03:35 by pholster      #+#    #+#                  #
#    Updated: 2020/05/25 19:03:35 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

import re
import os
import sys
import glob
import pathlib
import argparse

# WIP make more robust

sourceDir = "src"
description="Checks and report's functions that are missing quick info"

targetPath = os.path.dirname(sys.path[0]) # Removes '/tools' from the end
os.chdir(targetPath)

argParser = argparse.ArgumentParser(description=description)
argParser.add_argument("directory", nargs="?",
	default=sourceDir, type=pathlib.Path,
	help="directory to search")

args = argParser.parse_args()

noQuickInfoRegex = r"^\n(?!static)\s{0}\S+\s.*?\n?\((.|\n)*\)\n"
globPattern = os.path.join(args.directory, "**/*[!_test].c")
for file in glob.glob(globPattern, recursive=True):
	try:
		with open(file, "r") as fd:
			content = fd.read()
		regexMataches = re.search(noQuickInfoRegex, content, flags=re.MULTILINE)
		if regexMataches == None:
			continue
		functionName = regexMataches.group(0).split()[-1] # Select function name
		functionName = functionName[functionName.count("*"):-1] # Trim off * and (
		print(f"Warning: Function '{functionName}' missing quick info in '{file}'")
	except:
		print(f"Error: Checking quickInfo of file '{file}'")
