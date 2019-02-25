/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lsttointarr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 10:14:49 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:09:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_lsttointarr(t_list *lst)
{
	int		*arr;
	int		*n;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_lstlen(lst);
	if (len == 0)
		return (NULL);
	arr = (int *)ft_memalloc(sizeof(int) * (len + 1));
	if (arr == NULL)
		return (NULL);
	while (lst != NULL)
	{
		n = (int *)lst->content;
		arr[i] = *n;
		lst = lst->next;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
