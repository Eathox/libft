#include "utf8.h"

size_t	ft_utf8len(t_wchar c) {
	if (c >= 0x0000 && c <= 0x007F)
		return (1);
	if (c >= 0x0080 && c <= 0x07FF)
		return (2);
	if (c >= 0x0800 && c <= 0xFFFF)
		return (3);
	if (c >= 0x10000 && c <= 0x10FFFF)
		return (4);
	return (0);
}
