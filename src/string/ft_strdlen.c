/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:20:03 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 14:19:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strdlen(char *str, char *dlm)
{
	size_t		len;
	long long	bytes[2];

	len = 0;
	if (str == NULL)
		return (0);
	ft_chrsetbytes(bytes, dlm);
	while (str[len] != '\0' && ft_chrinbytes(bytes, str[len]) == FALSE)
		len++;
	return (len);
}
