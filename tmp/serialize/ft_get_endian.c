#include "serialize.h"

t_endian	ft_get_endian(void) {
	const t_uint32	i = 1;

	if (*((t_uint8*)&i) == 1)
		return (ENDIAN_LITTLE);
	return (ENDIAN_BIG);
}
