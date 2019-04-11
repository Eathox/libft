/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strreplace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 12:11:16 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strreplace(char **str1, const char *str2)
{
	ft_strdel(str1);
	*str1 = (char *)str2;
	return ((char *)str2);
}
