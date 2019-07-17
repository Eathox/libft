/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getnextdline.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:25:35 by pholster       #+#    #+#                */
/*   Updated: 2019/07/17 20:05:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static t_gnl	*getlst(const int fd, t_gnl *lst)
{
	t_gnl	*newlst;

	while (lst != NULL)
	{
		if (lst->fd == fd)
			return (lst);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	newlst = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	if (newlst == NULL)
		return (NULL);
	newlst->fd = fd;
	if (lst != NULL)
		lst->next = newlst;
	return (newlst);
}

static int		lastline(char **line, t_gnl *lst)
{
	size_t	len;

	if (lst->str != NULL)
	{
		len = lst->len;
		*line = ft_memalloc(len + 1);
		if (*line == NULL)
			return (-1);
		ft_memcpy(*line, lst->str, len);
		ft_strdel(&lst->str);
		lst->len = 0;
		return (len);
	}
	lst->len = 0;
	*line = ft_strnew(0);
	if (*line == NULL)
		return (-1);
	return (0);
}

static int		strmerge(char **str1, char *str2, size_t *len, ssize_t ret)
{
	char	*str;

	if (*str1 == NULL)
		*str1 = ft_memdup(str2, ret);
	else
	{
		str = ft_memalloc(*len + ret);
		if (str == NULL)
			return (FALSE);
		ft_memcpy(str, *str1, *len);
		ft_memcpy(&str[*len], str2, ret);
		ft_memreplace((void **)str1, str);
	}
	*len += ret;
	if (*str1 == NULL)
		return (FALSE);
	return (TRUE);
}

static ssize_t	readfile(char **line, char *buff, t_gnl *lst, char dlm)
{
	ssize_t	ret;
	ssize_t	newl;

	newl = ft_memindex(lst->str, dlm, lst->len);
	while (newl == -1)
	{
		ret = read(lst->fd, buff, BUFF_SIZE);
		if (ret == 0)
			break ;
		if (ret == -1 || strmerge(&lst->str, buff, &lst->len, ret) == FALSE)
			return (-1);
		newl = ft_memindex(lst->str, dlm, lst->len);
	}
	if (newl == -1)
		return (lastline(line, lst));
	*line = ft_memalloc(newl + 1);
	if (*line == NULL)
		return (-1);
	ft_memcpy(*line, lst->str, newl);
	lst->len -= (newl + 1);
	ft_memreplace((void **)&lst->str, ft_memdup(&lst->str[newl + 1], lst->len));
	if (lst->str == NULL)
		return (-1);
	return (newl + 1);
}

ssize_t			ft_getnextdline(const int fd, char **line, char dlm)
{
	static t_gnl	*head;
	t_gnl			*lst;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	lst = getlst(fd, head);
	if (lst == NULL)
		return (-1);
	if (head == NULL)
		head = lst;
	ret = readfile(line, buff, lst, dlm);
	return (ret);
}
