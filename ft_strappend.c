/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strappend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 19:47:57 by pholster       #+#    #+#                */
/*   Updated: 2019/02/17 19:47:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strappend(char **dst, char *src)
{
	char	*temp;

	temp = ft_strjoin(*dst, src);
	ft_strdel(dst);
	*dst = temp;
}
