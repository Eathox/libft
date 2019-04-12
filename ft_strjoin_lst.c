/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_lst.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:00:01 by pholster       #+#    #+#                */
/*   Updated: 2019/04/12 12:21:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	totallen(const t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst != NULL)
	{
		len += lst->content_size;
		lst = lst->next;
	}
	return (len + 1);
}

static char		*joinstrs(char *str, const t_list *lst)
{
	char	*content;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	content = (char *)(lst->content);
	while (lst != NULL)
	{
		if (content == NULL || k >= lst->content_size)
		{
			k = 0;
			lst = lst->next;
			if (lst == NULL)
				break ;
			content = (char *)(lst->content);
		}
		str[i] = content[k];
		i++;
		k++;
	}
	return (str);
}

char			*ft_strjoin_lst(const t_list *lst)
{
	char	*str;

	if (lst == NULL)
		return (NULL);
	str = ft_strnew(totallen(lst));
	if (str == NULL)
		return (NULL);
	str = joinstrs(str, lst);
	return (str);
}
