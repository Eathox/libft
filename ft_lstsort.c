/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:08:43 by pholster       #+#    #+#                */
/*   Updated: 2019/03/15 17:46:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	spawhead(t_list **alst, t_list *sortlst, t_list *prvsort)
{
	if (sortlst != *alst)
	{
		prvsort->next = sortlst->next;
		sortlst->next = *alst;
		*alst = sortlst;
	}
}

void		ft_lstsort(t_list **alst,
						int (*f)(const void *, size_t, const void *, size_t))
{
	t_list	*lst;
	t_list	*prvlst;
	t_list	*sortlst;
	t_list	*prvsort;

	if (alst == NULL || f == NULL)
		return ;
	lst = (*alst)->next;
	prvlst = *alst;
	sortlst = *alst;
	while (lst != NULL)
	{
		if (f(sortlst->content, sortlst->content_size,
											lst->content, lst->content_size))
		{
			prvsort = prvlst;
			sortlst = lst;
		}
		prvlst = lst;
		lst = lst->next;
	}
	spawhead(alst, sortlst, prvsort);
	if ((*alst)->next != NULL)
		ft_lstsort(&(*alst)->next, f);
}
