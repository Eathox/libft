# The header files are in the same directory as the source files. But as a
# result the include paths are relative to how the src directory is structured
# Once the header files get moved to the build directory these paths are no longer valid
# this awk script changes include statements that end with a format like "name/include/name.h" to "ft/name.h"

index($0, "#include") == 0 {print; next}
index($0, "#include") == 1 {
	path = $2
	gsub("\"", "", path)

	pathArrayCount = split(path, pathArray, "/")
	gsub(".h", "", pathArray[pathArrayCount])

	# Check if that path ends with {name}/include/{name}, text being the same on both sides
	if (pathArray[pathArrayCount-1] != "include") {print; next}
	if (pathArray[pathArrayCount-2] != pathArray[pathArrayCount]) {print; next}

	# Add .h back and prefix path with ft
	pathArray[pathArrayCount-2] = pathArray[pathArrayCount-2] ".h"
	pathArray[0] = "ft"

	newPath = join(pathArray, pathArrayCount - 2, "/")
	sub(path, newPath, $0)
	print
}

# Joins an array to one string
function join(array, end, sep)
{
    result = array[0]
    for (i = 1; i <= end; i++)
        result = result sep array[i]
    return result
}
