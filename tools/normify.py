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
	sourceDir,
)
targetFiles = (
	"author",
	"make.mk",
	"makefile",
)

# --- Create the normDir and copy over important files
targetPath = os.path.dirname(sys.path[0]) # Removes '/tools' from the end
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

# --- Def replace file content function
def replaceContent(file, findRegex, replaceRegex):
	with open(file, "r") as fd:
		content = fd.read()
	content = re.sub(findRegex, replaceRegex, content, flags=re.MULTILINE)
	with open(file, "w") as fd:
		fd.write(content)

# --- Def replace file content function
def replaceContentGlob(globPattern, findRegex, replaceRegex):
	for file in glob.glob(globPattern, recursive=True):
		try:
			replaceContent(file, findRegex, replaceRegex)
		except:
			print(f"Error: Replacing content of file '{file}'")

# --- Remove test files
normPath = os.path.join(targetPath, normDir)
os.chdir(normPath)

globPattern = os.path.join(sourceDir, "**/*_test.c")
for file in glob.glob(globPattern, recursive=True):
	try:
		os.remove(file)
	except:
		print(f"Error: Removing file '{file}'")

# --- Add newline between function prototype and quick info
findRegex = r"(\/\*\n(\*{2}.*\n)*\*\/)(\n\s{0}\S+\s.*?\n?\()"
replaceRegex = r"\1\n\3"
globPattern = os.path.join(sourceDir, "**/*.c")
replaceContentGlob(globPattern, findRegex, replaceRegex)

# --- Remove all test makefile targets
findRegex = r"\n*tests\s?\+=.*"
replaceRegex = r""
globPattern = os.path.join(sourceDir, "**/make.mk")
replaceContentGlob(globPattern, findRegex, replaceRegex)

# --- Add a new line between ) {
findRegex = r"([ \t]*)(.*)\) {"
replaceRegex = r"\1\2)\n\1{"
globPattern = os.path.join(sourceDir, "**/*.c")
replaceContentGlob(globPattern, findRegex, replaceRegex)

