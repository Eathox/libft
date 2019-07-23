/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puterror.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 16:58:45 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

t_bool		ft_puterror(const char *str)
{
	if (str == NULL)
		return (write(2, "(null)", 6) != -1);
	return (write(2, str, ft_strlen(str)) != -1);
}
