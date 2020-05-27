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

sourceDir = "src"

targetPath = os.path.dirname(sys.path[0]) # Removes /tools from the end
os.chdir(targetPath)

noQuickInfoRegex = r"^\n(?!static)\s{0}\S+\s.*?\n?\((.|\n)*\)\n"
globPattern = os.path.join(sourceDir, "**/*[!_test].c")
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
