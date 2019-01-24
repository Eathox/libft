/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupperstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:20:29 by pholster       #+#    #+#                */
/*   Updated: 2019/01/15 15:01:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_toupperstr(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
		return ;
	while (s[++i] != '\0')
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
}
