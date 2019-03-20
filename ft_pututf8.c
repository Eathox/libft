/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pututf8.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/03/20 16:30:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pututf8(t_wchar c)
{
	t_wchar	bit;
	size_t	shift;
	size_t	i;
	size_t	len;

	i = 1;
	len = ft_utf8len(c);
	if (len == 1)
		bit = (0x80 | c) & 0x7f;
	else if (len == 2)
		bit = (0xe0 | (c >> 6)) & 0xdf;
	else if (len == 3)
		bit = (0xf0 | (c >> 12)) & 0xef;
	else if (len == 4)
		bit = (0xf8 | (c >> 18)) & 0xf7;
	write(1, &bit, 1);
	while (i < len)
	{
		i++;
		shift = 6 * (len - i);
		bit = (0xc0 | (c >> shift)) & 0xbf;
		write(1, &bit, 1);
	}
}
