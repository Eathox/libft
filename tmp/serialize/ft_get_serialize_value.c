#include "ft/mem.h"

#include "serialize.h"
#include "priv.h"

ssize_t		ft_get_serialize_value(t_serialize *serialize, t_uint8 *result,
				size_t size) {
	size_t	fit;
	size_t	max_fit;

	fit = size;
	if (serialize->use_buffer == false)
		return (-1);
	if (serialize->content == NULL)
	{
		if (ft_read_serialize(serialize) < 0)
			return (-1);
	}
	if (serialize->pos > serialize->content_size)
		return (0);
	max_fit = serialize->content_size - serialize->pos;
	if (fit > max_fit)
		fit = max_fit;
	ft_memcpy(result, &serialize->content[serialize->pos], fit);
	return (fit);
}
