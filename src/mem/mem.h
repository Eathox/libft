/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mem.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 23:47:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <sys/types.h>
# include <stdbool.h>

void		*ft_calloc(
	size_t count,
	size_t size
);

void		*ft_memalloc(
	size_t size
);

void		ft_memdel(
	void **adr
);

void		*ft_memset(
	void *mem,
	int c,
	size_t len
);

// Put in
// void		ft_arraydel(void ***array, void (*del)(void**));
// void		ft_bzero(void *mem, size_t len);
// int			ft_memcmp(const void *mem1, const void *mem2, size_t len);
// bool		ft_memequ(const void *mem1, const void *mem2, size_t len);
// void		*ft_memccpy(void *dst, const void *src, char c, size_t len);
// void		*ft_memchr(const void *mem, char c, size_t len);
// void		*ft_memcpy(void *dst, const void *src, size_t len);
// void		*ft_memdup(const void *src, size_t len);
// void		*ft_memmove(void *dst, const void *src, size_t len);
// void		*ft_memrchr(const void *str, char c, size_t len);
// void		*ft_memrcpy(void *dst, const void *src, size_t len);
// void		*ft_memset4(void *mem, int c, size_t len);
// void		ft_memrev(void *mem, size_t len);

// Choping block (maybe)
// ssize_t		ft_memindex(const void *mem, char c, size_t len);
// void		*ft_pointerreplace(void **ptr1, const void *ptr2);

#endif
