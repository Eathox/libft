#!/usr/bin/env python3

import re
import os
import sys
import glob
import shutil

normDir = "norm"
targetFiles = (
	"author",
	"makefile"
)
targetDirectories = (
	"makefile_mk",
	# ".vscode",
	"src"
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
		print(f"Error copying directory: '{directory}'")

for file in targetFiles:
	try:
		shutil.copy(file, os.path.join(normDir, file))
	except:
		print(f"Error copying file: '{file}'")

# --- Replace file content function
def replaceContent(file, findRegex, replaceRegex):
	with open(file, "r") as fd:
		content = fd.read()
	content = re.sub(findRegex, replaceRegex, content)
	with open(file, "w") as fd:
		fd.write(content)

# --- Clean up the normDir and its files
normPath = os.path.join(targetPath, normDir)
os.chdir(normPath)

for file in glob.glob("src/**/*_test.c", recursive=True):
	try:
		os.remove(file)
	except:
		print(f"Error removing file: '{file}'")

# Add newline between function prototype and quick info
for file in glob.glob("src/**/*.c", recursive=True):
	quickInfoRegex = r"(\/\*\n(.|\n)*\n?\*\/)(\n.*\n?\()"
	quickInfoReplace = r"\1\n\3"
	try:
		replaceContent(file, quickInfoRegex, quickInfoReplace)
	except:
		print(f"Error replace content of file: '{file}'")

# Remove all test makefile targets
for file in glob.glob("src/**/make.mk", recursive=True):
	testRulesRegex = r"\n*tests\s?\+=.*"
	testRulesReplace = r""
	try:
		replaceContent(file, testRulesRegex, testRulesReplace)
	except:
		print(f"Error replace content of file: '{file}'")
