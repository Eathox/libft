/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:30:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/01 12:02:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	istobig(const char *s, int isneg)
{
	if (isneg == -1 && ft_strcmp(s, "9223372036854775808") > 0)
		return (TRUE);
	if (isneg == 1 && ft_strcmp(s, "9223372036854775807") > 0)
		return (TRUE);
	return (FALSE);
}

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
	if (ft_strlen(&s[i]) >= 19 && ft_isdigitstr(&s[i]) && istobig(&s[i], isneg))
		return (0 - (s[i - 1] != '-'));
	while (ft_isdigit(s[i]))
	{
		result = (result * 10) + s[i] - '0';
		i++;
	}
	return ((int)(result * isneg));
}
