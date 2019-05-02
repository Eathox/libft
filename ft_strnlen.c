/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/05/02 16:20:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		preparemagic(long long *himagic, long long *lomagic)
{
	*himagic = 0x80808080L;
	*lomagic = 0x01010101L;
	*himagic |= (*himagic << 32);
	*lomagic |= (*lomagic << 32);
}

static size_t	castmagic(long long *str, long long himagic, long long lomagic,
					size_t n)
{
	char	*longword;
	size_t	i;
	size_t	len;

	len = 0;
	while (n >= 8)
	{
		if (((str[len] - lomagic) & (~str[len] & himagic)) != 0)
		{
			i = 0;
			longword = (char *)&str[len];
			while (i < 8)
			{
				if (longword[i] == 0)
					return ((len * 8) + i);
				i++;
			}
		}
		n -= 8;
		len++;
	}
	return (len * 8);
}

size_t			ft_strnlen(const char *str, size_t n)
{
	long long	himagic;
	long long	lomagic;
	size_t		len;

	len = 0;
	while (len < n && str[len] != '\0' && ((unsigned long)&str[len]) % 8 != 0)
		len++;
	if (len == n || str[len] == '\0')
		return (len);
	preparemagic(&himagic, &lomagic);
	len += castmagic((long long *)&str[len], himagic, lomagic, n - len);
	while (len < n && str[len] != '\0')
		len++;
	return (len);
}
