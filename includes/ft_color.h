/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_color.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:57:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include "ft_bool.h"
# include <string.h>
# include <stdint.h>

typedef	unsigned int	t_color;

char		*ft_colorstr(int color);
t_color		*ft_colorhextorgba(t_color color);
t_color		ft_colorrgbatohex(t_color r, t_color g, t_color b, t_color a);
ssize_t		ft_colorcode(char *str);
ssize_t		ft_colorlcode(char *str);
ssize_t		ft_colorncode(char *str, size_t n);

#endif
