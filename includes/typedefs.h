/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   typedefs.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 15:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/07/14 15:21:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPEDEFS_H
# define FT_TYPEDEFS_H

# include "libft.h"

typedef	int				t_wchar;
typedef	unsigned int	t_color;
typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

typedef struct			s_gnl
{
	int				fd;
	char			*str;
	size_t			len;
	struct s_gnl	*next;
}						t_gnl;

# define MAX_DOUBLE_PRECISION 24
# define BUFF_SIZE	42
# define FALSE	0
# define TRUE	1

#endif
