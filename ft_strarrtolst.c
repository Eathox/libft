/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrtolst.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:48:15 by pholster       #+#    #+#                */
/*   Updated: 2019/02/06 03:34:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*freeret(t_list **lst)
{
	ft_lstdel(lst, &ft_lstmemdel);
	return (NULL);
}

t_list			*ft_strarrtolst(const char **arr)
{
	t_list	*lst;
	t_list	*prvlst;
	t_list	*returnlst;
	int		i;

	i = 0;
	if (stra == NULL)
		return (NULL);
	returnlst = ft_lstnew(arr[i], ft_strlen(arr[i]) + 1);
	if (returnlst == NULL)
		return (NULL);
	prvlst = returnlst;
	i++;
	while (arr[i] != 0)
	{
		lst = ft_lstnew(arr[i], ft_strlen(arr[i]) + 1);
		if (lst == NULL)
			return (freeret(&returnlst));
		ft_lstaddbck(&prvlst, lst);
		prvlst = lst;
		i++;
	}
	return (returnlst);
}
