#include "ft/mem.h"

#include "str.h"

void	ft_strappend(char **dst, const char *src) {
	ft_pointerreplace((void **)dst, ft_strjoin(*dst, src));
}
