/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 17:47:13 by pholster       #+#    #+#                */
/*   Updated: 2019/02/18 17:52:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getchar(void)
{
	char	*str;

	get_next_line(1, &str);
	if (str[0] == '\0')
		str[0] = '\n';
	return (str[0]);
}
