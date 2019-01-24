/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intarrtolst.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 10:14:45 by pholster       #+#    #+#                */
/*   Updated: 2019/01/23 14:15:45 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_intarrtolst(int *arr, int len)
{
	t_list	*returnlst;
	t_list	*prvlst;
	t_list	*lst;
	int		i;
	int		n;

	i = 0;
	if (arr == NULL)
		return (NULL);
	n = arr[i];
	returnlst = ft_lstnew(&n, (sizeof(int) * ft_intlen(n)));
	if (returnlst == NULL)
		return (NULL);
	prvlst = returnlst;
	while (++i < len)
	{
		n = arr[i];
		lst = ft_lstnew(&n, (sizeof(int) * ft_intlen(n)));
		if (lst == NULL)
			return (NULL);
		ft_lstaddbck(&prvlst, lst);
		prvlst = returnlst;
	}
	return (returnlst);
}
