/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/03/26 18:19:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_chrdin(const char *str, const char *dlm)
{
	size_t		i;
	long long	chars[2];

	i = 0;
	(void)str;
	ft_memset(chars, 0, sizeof(chars));
	while (dlm[i] != '\0')
	{
		chars[0] |= (1 << dlm[i]);
		i++;
	}
	ft_putendl("");
	ft_putbytes(&chars[1], sizeof(chars[1]));
	ft_putendl("");
	ft_putbytes(&chars[0], sizeof(chars[0]));
	ft_putendl("");
	return (FALSE);
}

// int			ft_chrdin(const char *str, const char *dlm)
// {
// 	return (ft_chrdindex(str, dlm) != -1);
// }
