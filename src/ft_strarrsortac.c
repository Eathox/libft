/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrsortac.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 23:50:25 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool		ft_strarrsortac(char *current, char *str)
{
	int		result;

	result = ft_strcmp(current, str);
	return (result < 0 && result != 0);
}
