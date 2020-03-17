/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   priv.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 17:51:50 by pholster       #+#    #+#                */
/*   Updated: 2020/02/15 17:51:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRIV_H
# define FT_PRIV_H

# include <stdlib.h>

typedef struct	s_gnl
{
	int				fd;
	char			*str;
	size_t			len;
	struct s_gnl	*next;
}				t_gnl;

#endif
