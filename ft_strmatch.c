/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmatch.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 20:44:25 by pholster       #+#    #+#                */
/*   Updated: 2019/01/15 15:02:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strmatch(const char *s, const char *needle)
{
	if (s == NULL || needle == NULL)
		return (FALSE);
	if (needle[0] == '\0' && s[0] == '\0')
		return (TRUE);
	if (needle[0] != s[0] && needle[0] != '*')
		return (FALSE);
	if (needle[0] == '*' && s[0] != '\0')
	{
		return (ft_strmatch(&s[1], &needle[1]) ||
				ft_strmatch(&s[1], &needle[0]) ||
				ft_strmatch(&s[0], &needle[1]));
	}
	return (ft_strmatch(&s[1], &needle[1]));
}
