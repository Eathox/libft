/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:22:38 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 22:59:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freeret(char **ret, char *cs)
{
	ft_strdel(&cs);
	return (ret);
}

static void	addword(char **tab, char *str)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	tab[i] = str;
}

static char	**create_strarr(char const *s, char *cs)
{
	int		i;
	char	**tab;
	int		wrdcount;

	i = 0;
	if (s == NULL)
		return (NULL);
	wrdcount = ft_wrddcount(s, cs);
	tab = (char **)malloc(sizeof(char *) * wrdcount + 1);
	if (tab == NULL)
		return (NULL);
	while (i <= wrdcount)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char			*cs;
	char			**tab;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	cs = ft_chrtostr(c);
	tab = create_strarr(s, cs);
	if (tab == NULL)
		return (freeret(NULL, cs));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = 0;
		else if (j == 0)
		{
			addword(tab, ft_strndup(&s[i], ft_strdlen(&s[i], cs)));
			j = 1;
		}
		i++;
	}
	return (freeret(tab, cs));
}
