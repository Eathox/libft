/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lsttointarr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 10:14:49 by pholster       #+#    #+#                */
/*   Updated: 2019/01/17 10:15:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_lsttointarr(t_list *lst)
{
	int		*n;
	int		i;
	int		*arr;
	t_list	**alst;
	int		len;

	i = 0;
	len = ft_lstlen(lst);
	if (len == 0)
		return (NULL);
	alst = &lst;
	arr = (int *)malloc(sizeof(int) * (len + 1));
	if (arr == NULL)
		return (NULL);
	while (lst != NULL)
	{
		n = (int *)lst->content;
		arr[i++] = *n;
		lst = lst->next;
	}
	arr[i] = 0;
	return (arr);
}
