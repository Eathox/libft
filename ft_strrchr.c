/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:26:07 by pholster      #+#    #+#                 */
/*   Updated: 2019/01/11 21:00:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;
	int	i;

	i = -1;
	l = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			l = i;
	if (s[i] == c)
		l = i;
	if (l != -1)
		return ((char *)&s[l]);
	return (NULL);
}
