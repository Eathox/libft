/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intarrtolst.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 10:14:45 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 13:23:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*freeret(t_list **lst)
{
	ft_lstdel(lst, &ft_lstmemdel);
	return (NULL);
}

t_list			*ft_intarrtolst(const int *arr, int len)
{
	t_list	*returnlst;
	t_list	*prvlst;
	t_list	*newlst;
	int		num;
	int		i;

	i = 0;
	if (arr == NULL)
		return (NULL);
	num = arr[i];
	returnlst = ft_lstnew(&num, (sizeof(int) * ft_intlen(num)));
	if (returnlst == NULL)
		return (NULL);
	prvlst = returnlst;
	while (i < len)
	{
		i++;
		num = arr[i];
		newlst = ft_lstnew(&num, (sizeof(int) * ft_intlen(num)));
		if (newlst == NULL)
			return (freeret(&returnlst));
		prvlst->next = newlst;
		prvlst = returnlst;
	}
	return (returnlst);
}
