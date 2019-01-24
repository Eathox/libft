/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:30:39 by pholster       #+#    #+#                */
/*   Updated: 2019/01/23 14:15:54 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *s)
{
	unsigned long	result;
	int				isneg;
	int				i;

	i = 0;
	isneg = 1;
	result = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
		isneg = -1;
	if (ft_chrin("+-", s[i]))
		i++;
	while (ft_isdigit(s[i]))
		result = (result * 10) + s[i++] - '0';
	return (result * isneg);
}
