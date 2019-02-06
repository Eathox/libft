/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lsttostrarr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:55:27 by pholster       #+#    #+#                */
/*   Updated: 2019/02/06 03:34:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freeret(char **stra)
{
	free(stra);
	return (NULL);
}

char		**ft_lsttostrarr(t_list *lst)
{
	int		i;
	char	*str;
	char	**stra;
	int		len;

	i = 0;
	len = ft_lstlen(lst);
	if (len == 0)
		return (NULL);
	stra = ft_strarrnew(len);
	if (stra == NULL)
		return (NULL);
	while (lst != NULL)
	{
		str = ft_strdup((char *)lst->content);
		if (str == NULL)
			return (freeret(stra));
		stra[i] = str;
		lst = lst->next;
		i++;
	}
	stra[i] = 0;
	return (stra);
}
