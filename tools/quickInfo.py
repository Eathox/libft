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

# --- Search for missing quick info
noQuickInfoRegex = r"^(?!\/\*\n(\*{2}.*?\n)*\*\/)\n(?!\bstatic\b)(\b.*?\n?\()"
globPattern = os.path.join(sourceDir, "**/*[!_test].c")
for file in glob.glob(globPattern, recursive=True):
	try:
		with open(file, "r") as fd:
			content = fd.read()
		regexMataches = re.search(noQuickInfoRegex, content, flags=re.MULTILINE)
		if regexMataches == None:
			continue
		functionName = regexMataches.group(0).split()[-1] # Select function name
		functionName = functionName[functionName.count("*"):-1] # Trim off '*' and '('
		print(f"Warning: Function '{functionName}' missing quick info in '{file}'")
	except:
		print(f"Error: Checking quickInfo of file '{file}'")
