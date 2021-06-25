#include "str.h"

char	*ft_strtrim(const char *str) {
	return (ft_strdtrim(str, " \n\t"));
}
