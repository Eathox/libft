/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:22:38 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 18:16:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**create_strarr(char const *s, char *cs)
{
	char	**tab;
	int		wrdcount;

	if (s == NULL)
		return (NULL);
	wrdcount = ft_wrddcount(s, cs);
	tab = (char **)malloc(sizeof(char *) * wrdcount + 1);
	if (tab == NULL)
		return (NULL);
	tab[wrdcount] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	k;
	int				j;

	i = 0;
	k = 0;
	j = 0;
	tab = create_strarr(s, ft_chrtostr(c));
	if (tab == NULL)
		return (NULL);
	while (s[ft_abs(i)] != '\0')
	{
		if (s[i] == c)
			j = 0;
		else if (j == 0)
		{
			tab[k] = ft_strndup(&s[i], ft_strdlen(&s[i], ft_chrtostr(c)));
			j = 1;
			k++;
		}
		i++;
	}
	return (tab);
}
