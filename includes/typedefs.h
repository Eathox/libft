/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   typedefs.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 15:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/03/20 15:32:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPEDEFS_H
# define FT_TYPEDEFS_H

typedef	unsigned int	t_wchar;
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

# define FALSE	0
# define TRUE	1

#endif
