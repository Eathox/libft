/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libtest.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 14:22:47 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 14:22:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBTEST_H
# define FT_LIBTEST_H

# include <stdarg.h>
# include "../includes/typedefs.h"

void	ft_realfree(void *ptr);
void	*ft_realmalloc(size_t size);
t_bool	ft_malloclstempty(void);
size_t	ft_malloclastsize(void);
void	ft_mallocclearlst(void);
size_t	ft_malloclstlen(void);

#endif