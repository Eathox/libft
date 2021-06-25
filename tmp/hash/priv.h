#ifndef FT_PRIV_H
# define FT_PRIV_H

# include "hash.h"

bool			ft_keyequ(const t_hashlist *entry, const void *key,
					size_t keysize);

#endif
