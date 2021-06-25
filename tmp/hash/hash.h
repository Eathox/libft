#ifndef FT_HASH_H
# define FT_HASH_H

# include <string.h>
# include <stdbool.h>

typedef struct	s_hashlist
{
	void				*value;
	void				*key;
	size_t				keysize;
	struct s_hashlist	*next;
}				t_hashlist;

typedef struct	s_hashmap
{
	size_t				size;
	t_hashlist			**arr;
	size_t				(*f)(const void *, size_t);
}				t_hashmap;

t_hashmap		*ft_hashmapnew(size_t size, size_t (*f)(const void *, size_t));
size_t			ft_hashsdbm(const void *key, size_t size);
size_t			ft_hashdjb2(const void *key, size_t size);
size_t			ft_hashdjb2a(const void *key, size_t size);
size_t			ft_hashsdbm_nocase(const void *key, size_t size);
size_t			ft_hashdjb2_nocase(const void *key, size_t size);
size_t			ft_hashdjb2a_nocase(const void *key, size_t size);
void			ft_hashmapdel(t_hashmap *map, void (*del)(void *));
void			*ft_hashmapget_str(const t_hashmap *map, const char *key);
bool			ft_hashmapadd_str(const t_hashmap *map, const char *key,
					void *value);
void			ft_hashmapdelone_str(const t_hashmap *map, const char *key,
					void (*del)(void *));
void			*ft_hashmapget(const t_hashmap *map, const void *key,
					size_t keysize);
bool			ft_hashmapadd(const t_hashmap *map, const void *key,
					size_t keysize, void *value);
void			ft_hashmapdelone(const t_hashmap *map, const void *key,
					size_t keysize, void (*del)(void *));

#endif
