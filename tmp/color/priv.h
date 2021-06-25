#ifndef PRIV_H
# define PRIV_H

# include "color.h"

t_uint8		convert_hex_channel(
	char const *channel
);

void		convert_byte_channel(
	char *dst,
	t_uint8 channel
);

#endif
