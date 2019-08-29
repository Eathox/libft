/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:27:13 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_H
# define FT_HASH_H

# include "ft_bool.h"
# include <string.h>

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
	size_t				(*f)(char *);
}				t_hashmap;

t_hashmap		*ft_hashmapnew(size_t size, size_t (*f)(char *));
size_t			ft_hashsdbm(char *str);
size_t			ft_hashdjb2(char *str);
size_t			ft_hashdjb2a(char *str);
size_t			ft_hashsdbm_nocase(char *str);
size_t			ft_hashdjb2_nocase(char *str);
size_t			ft_hashdjb2a_nocase(char *str);
void			ft_hashmapdel(t_hashmap *map, void (*del)(void *));
t_bool			hs_keyequ(t_hashlist *entry, void *key, size_t keysize);
void			*ft_hashmapget_str(t_hashmap *map, void *key);
t_bool			ft_hashmapadd_str(t_hashmap *map, void *key, void *value);
void			ft_hashmapdelone_str(t_hashmap *map, void *key,
					void (*del)(void *));
void			*ft_hashmapget(t_hashmap *map, void *key, size_t keysize);
t_bool			ft_hashmapadd(t_hashmap *map, void *key, size_t keysize,
					void *value);
void			ft_hashmapdelone(t_hashmap *map, void *key, size_t keysize,
					void (*del)(void *));

#endif
