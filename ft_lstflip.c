/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstflip.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 13:15:33 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 15:17:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstflip(t_list **alst)
{
	t_list	*lst;
	t_list	*prvlst;
	t_list	*nxtlst;

	if (alst == NULL || *alst == NULL)
		return ;
	lst = *alst;
	prvlst = NULL;
	while (lst != NULL)
	{
		nxtlst = lst->next;
		lst->next = prvlst;
		prvlst = lst;
		lst = nxtlst;
	}
	*alst = prvlst;
}
