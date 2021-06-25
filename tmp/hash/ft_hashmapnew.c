#include "ft/mem.h"

#include "hash.h"

t_hashmap		*ft_hashmapnew(size_t size, size_t (*f)(const void *, size_t)) {
	t_hashmap	*new;

	new = (t_hashmap *)ft_memalloc(sizeof(t_hashmap));
	if (new == NULL)
		return (NULL);
	new->arr = (t_hashlist **)ft_memalloc(sizeof(t_hashlist *) * size);
	if (new->arr == NULL)
	{
		free(new);
		return (NULL);
	}
	new->f = f;
	new->size = size;
	return (new);
}
