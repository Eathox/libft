#!/usr/bin/env python3
# Deprecated: norm is no longer required

import re
import os
import sys
import glob
import shutil
import string
import argparse

normDir = "norm"
sourceDir = "src"
targetDirectories = (
    sourceDir,
    "makefile_mk",
)
targetFiles = (
    "author",
    "make.mk",
    "makefile",
)

prettyTargets = []
for target in (targetDirectories + targetFiles):
	prettyTargets.append(str(target))
prettyTargets = ', '.join(prettyTargets)

description = "\n".join((
"Copy the project and apply norm rules that are intentionally ignored, norm actions:",
f"  * Copy: {prettyTargets}",
"  * Remove: src/guidelines.md",
"  * Remove: test function source files",
"  * Remove: test targets from all make.mk files",
"  * Add: newline between function definition and quickinfo",
"  * Add: newline between ') {'",
))
argParser = argparse.ArgumentParser(description=description, formatter_class=argparse.RawDescriptionHelpFormatter)
argParser.add_argument("--delete", action='store_const', const=True,
	help=f"delete {normDir} directory and exit")

args = argParser.parse_args()

# --- Change dir to project root
targetPath = os.path.dirname(sys.path[0]) # Removes '/tools' from the end
os.chdir(targetPath)

# --- Delete normdir and exit if '--delete' option is present
if (args.delete == True):
    print (f"Deleting: {normDir} directory")

    shutil.rmtree(normDir, ignore_errors=True)
    exit(0)

# --- Create the normDir and copy over important files
print (f"Copying: {prettyTargets}")

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

# --- Delete file function
def deleteFile(file):
    try:
        os.remove(file)
    except:
        print(f"Error: Removing file '{file}'")

# --- Replace file content function
def replaceContent(file, findRegex, replaceRegex):
    with open(file, "r") as fd:
        content = fd.read()
    content = re.sub(findRegex, replaceRegex, content, flags=re.MULTILINE)
    with open(file, "w") as fd:
        fd.write(content)

# --- Replace content of the files matching the glob function
def replaceContentGlob(globPattern, findRegex, replaceRegex):
    for file in glob.glob(globPattern, recursive=True):
        try:
            replaceContent(file, findRegex, replaceRegex)
        except:
            print(f"Error: Replacing content of file '{file}'")

# --- Change dir to norm directory
normPath = os.path.join(targetPath, normDir)
os.chdir(normPath)

# --- Remove src/guidelines.md
print ("Removing: src/Guidelines.md")

file = os.path.join(sourceDir, "Guidelines.md")
deleteFile(file)

# --- Remove test files
print ("Removing: all test function source files")

globPattern = os.path.join(sourceDir, "**/*_test.c")
for file in glob.glob(globPattern, recursive=True):
    deleteFile(file)

# --- Remove all test makefile targets
print ("Removing: test targets from all make.mk files")

findRegex = r"\n*\btests\b\s?\+=\s?.*$"
replaceRegex = r""
globPattern = os.path.join(sourceDir, "**/make.mk")
replaceContentGlob(globPattern, findRegex, replaceRegex)

# --- Add newline between function prototype and quick info
print ("Adding: newline between function prototype and quick info")

findRegex = r"^(\/\*\n(\*{2}.*?\n)*\*\/)\n(\b.*?\n?\()"
replaceRegex = r"\1\n\n\3"
globPattern = os.path.join(sourceDir, "**/*.c")
replaceContentGlob(globPattern, findRegex, replaceRegex)

# --- Add a new line between ') {'
print ("Adding: newline between ') {'")

findRegex = r"^([ \t]*)(.*?)\) {$"
replaceRegex = r"\1\2)\n\1{"
globPattern = os.path.join(sourceDir, "**/*.c")
replaceContentGlob(globPattern, findRegex, replaceRegex)
