/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readfile.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 18:30:38 by pholster       #+#    #+#                */
/*   Updated: 2019/07/05 12:02:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*freeret(t_list *lst)
{
	ft_lstdel(&lst, &ft_lstdelmem);
	return (NULL);
}

static char	*lsttostr(t_list *lst, size_t tottallen)
{
	size_t	i;
	t_list	*next;
	char	*str;

	i = 0;
	if (lst == NULL)
		return (ft_strnew(0));
	str = ft_strnew(tottallen);
	if (str == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->content != NULL)
			ft_memcpy(&str[i], lst->content, lst->content_size);
		i += lst->content_size;
		next = lst->next;
		free(lst);
		lst = next;
	}
	return (str);
}

static int	addtolst(t_list **lst, t_list **prv, char *str, size_t len)
{
	t_list	*new;

	new = ft_lstnew((const void *)str, len);
	if (new == NULL)
		return (FALSE);
	if (*lst == NULL)
		*lst = new;
	else
		(*prv)->next = new;
	*prv = new;
	return (TRUE);
}

char		*ft_readfile(int fd)
{
	t_list	*prv;
	t_list	*lst;
	ssize_t	ret;
	size_t	totallen;
	char	buff[BUFF_SIZE + 1];

	lst = NULL;
	prv = NULL;
	totallen = 0;
	ret = read(fd, buff, BUFF_SIZE);
	if (ret == -1)
		return (NULL);
	while (ret > 0)
	{
		totallen += ret;
		buff[ret] = '\0';
		if (addtolst(&lst, &prv, buff, ret) == FALSE)
			return (freeret(lst));
		if (ret == 0)
			break ;
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (freeret(lst));
	}
	return (lsttostr(lst, totallen));
}
