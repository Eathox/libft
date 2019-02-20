/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strreplace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 12:11:16 by pholster       #+#    #+#                */
/*   Updated: 2019/01/22 18:37:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char **s1, const char *s2)
{
	ft_strdel(s1);
	*s1 = s2;
	return (s2);
}
