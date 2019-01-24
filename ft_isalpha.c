/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:25:43 by pholster      #+#    #+#                 */
/*   Updated: 2019/01/11 20:59:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	else if (c >= 'A' && c <= 'Z')
		return (TRUE);
	return (FALSE);
}
