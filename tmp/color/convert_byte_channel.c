#include "priv.h"

/*
** * Convert a byte data channel to dst
*/
void	convert_byte_channel(
	char *dst,
	t_uint8 channel
) {
	const char	*base_str = "0123456789ABCDEF";

	dst[0] = base_str[(channel / 16)];
	dst[1] = base_str[(channel % 16)];
}
