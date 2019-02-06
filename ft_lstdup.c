/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 16:03:21 by pholster       #+#    #+#                */
/*   Updated: 2019/02/06 03:34:12 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*freeret(t_list **lst)
{
	ft_lstdel(lst, &ft_lstmemdel);
	return (NULL);
}

t_list			*ft_lstdup(t_list **alst)
{
	t_list	*lst;
	t_list	*prvlst;
	t_list	*returnlst;

	if (alst == NULL)
		return (NULL);
	returnlst = ft_lstnew(alst[0]->content, alst[0]->content_size);
	if (returnlst == NULL)
		return (NULL);
	prvlst = returnlst;
	alst = &(alst[0]->next);
	while (alst[0] != NULL)
	{
		lst = ft_lstnew(alst[0]->content, alst[0]->content_size);
		if (lst == NULL)
			return (freeret(&returnlst));
		ft_lstaddbck(&prvlst, lst);
		prvlst = lst;
		alst = &(alst[0]->next);
	}
	return (returnlst);
}
