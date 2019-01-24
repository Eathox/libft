/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lsttostrarr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:55:27 by pholster       #+#    #+#                */
/*   Updated: 2019/01/16 12:39:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lsttostrarr(t_list *lst)
{
	int		i;
	char	*str;
	char	**stra;
	int		len;

	i = 0;
	len = ft_lstlen(lst);
	if (len == 0)
		return (NULL);
	stra = (char **)malloc(sizeof(char *) * (len + 1));
	if (stra == NULL)
		return (NULL);
	while (lst != NULL)
	{
		str = ft_strdup((char *)lst->content);
		if (str == NULL)
			return (NULL);
		stra[i++] = str;
		lst = lst->next;
	}
	stra[i] = 0;
	return (stra);
}
