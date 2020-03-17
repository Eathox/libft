/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_lst.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:00:01 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:35:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/list.h"
#include "ft/mem.h"

#include "str.h"

static size_t	totallen(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst != NULL)
		len += ft_strlen(lst->content);
	return (len);
}

static char		*joinstrs(char *str, t_list *lst)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (lst != NULL)
	{
		len = ft_strlen(lst->content);
		ft_memcpy(&str[i], lst->content, len);
		i += len;
		lst = lst->next;
	}
	return (str);
}

char			*ft_strjoin_lst(t_list *lst)
{
	char	*str;

	str = ft_strnew(totallen(lst));
	if (str == NULL)
		return (NULL);
	str = joinstrs(str, lst);
	return (str);
}
