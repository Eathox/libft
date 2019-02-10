/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puterror.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/02/10 14:27:10 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_puterror(const char *s)
{
	if (s == NULL)
		write(2, "(null)", 6);
	else
		write(2, s, ft_strlen(s));
	return (0);
}
