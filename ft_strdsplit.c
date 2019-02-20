/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdsplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:22:38 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 10:29:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freeret(char ***tab)
{
	ft_strarrdel(tab);
	return (NULL);
}

char		**ft_strdsplit(const char *str, const char *delims)
{
	char			**tab;
	int				word;
	size_t			len;
	unsigned int	i;

	i = 0;
	word = 0;
	tab = ft_strarrnew((size_t)ft_wrddcount(str, delims));
	if (tab == NULL)
		return (NULL);
	while (str != NULL && str[i] != '\0')
	{
		if (ft_chrin(delims, str[i]) == FALSE)
		{
			len = ft_strdlen(&str[i], delims);
			tab[word] = ft_strndup(&str[i], len);
			if (tab[word] == NULL)
				return (freeret(&tab));
			word++;
			i += (len - 1);
		}
		i++;
	}
	return (tab);
}
