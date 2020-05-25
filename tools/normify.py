#!/usr/bin/env python3
# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    normify.py                                         :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/25 19:03:41 by pholster      #+#    #+#                  #
#    Updated: 2020/05/25 19:03:41 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

import re
import os
import sys
import glob
import shutil

normDir = "norm"
sourceDir = "src"
targetDirectories = (
	"makefile_mk",
	sourceDir
)
targetFiles = (
	"author",
	"makefile"
)

# --- Create the normDir and copy over important files
targetPath = os.path.dirname(sys.path[0]) # Removes /tools from the end
os.chdir(targetPath)

shutil.rmtree(normDir, ignore_errors=True)
os.mkdir(normDir)

for directory in targetDirectories:
	try:
		shutil.copytree(directory, os.path.join(normDir, directory))
	except:
		print(f"Error: Copying directory '{directory}'")

for file in targetFiles:
	try:
		shutil.copy(file, os.path.join(normDir, file))
	except:
		print(f"Error: Copying file '{file}'")

# --- Replace file content function
def replaceContent(file, findRegex, replaceRegex):
	with open(file, "r") as fd:
		content = fd.read()
	content = re.sub(findRegex, replaceRegex, content, flags=re.MULTILINE)
	with open(file, "w") as fd:
		fd.write(content)

# --- Clean up the normDir and its files
normPath = os.path.join(targetPath, normDir)
os.chdir(normPath)

globPattern = os.path.join(sourceDir, "**/*_test.c")
for file in glob.glob(globPattern, recursive=True):
	try:
		os.remove(file)
	except:
		print(f"Error: Removing file '{file}'")

# Add newline between function prototype and quick info
quickInfoRegex = r"(\/\*\n(\*{2}.*\n)*\*\/)(\n\s{0}\S+\s.*?\n?\()"
quickInfoReplace = r"\1\n\3"
globPattern = os.path.join(sourceDir, "**/*.c")
for file in glob.glob(globPattern, recursive=True):
	try:
		replaceContent(file, quickInfoRegex, quickInfoReplace)
	except:
		print(f"Error: Replacing content of file '{file}'")

# Remove all test makefile targets
testRulesRegex = r"\n*tests\s?\+=.*"
testRulesReplace = r""
globPattern = os.path.join(sourceDir, "**/make.mk")
for file in glob.glob(globPattern, recursive=True):
	try:
		replaceContent(file, testRulesRegex, testRulesReplace)
	except:
		print(f"Error: Replacing content of file '{file}'")
