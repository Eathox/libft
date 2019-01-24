/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_select.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:44:38 by pholster       #+#    #+#                */
/*   Updated: 2019/01/19 12:45:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_select(int con, void *var1, void *var2)
{
	if (con != 0)
		return (var1);
	return (var2);
}
