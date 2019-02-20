/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 18:26:53 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 19:53:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst == NULL || *alst == NULL)
		return ;
	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
