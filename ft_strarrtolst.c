/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrtolst.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:48:15 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 18:49:05 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_strarrtolst(char **stra)
{
	t_list	*lst;
	t_list	*prvlst;
	t_list	*returnlst;
	int		i;

	i = 0;
	if (stra == NULL)
		return (NULL);
	returnlst = ft_lstnew(stra[i], ft_strlen(stra[i]) + 1);
	if (returnlst == NULL)
		return (NULL);
	prvlst = returnlst;
	i++;
	while (stra[i] != 0)
	{
		lst = ft_lstnew(stra[i], ft_strlen(stra[i]) + 1);
		if (lst == NULL)
			return (NULL);
		ft_lstaddbck(&prvlst, lst);
		prvlst = lst;
		i++;
	}
	return (returnlst);
}
