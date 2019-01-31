/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:25:35 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 18:27:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*gnl_get_lst(const int fd, t_list *alst)
{
	t_list	*lst;

	while (alst != NULL)
	{
		if ((int)alst->FD == fd)
			return (alst);
		if (alst->next == NULL)
			break ;
		alst = alst->next;
	}
	lst = ft_lstnew(NULL, 0);
	lst->FD = fd;
	if (alst != NULL)
		alst->next = lst;
	return (lst);
}

static int		gnl_last_line(char **line, t_list *lst)
{
	char *str;

	str = (char *)lst->STR;
	if (str != NULL && str[0] != '\0')
	{
		*line = ft_strdup(lst->STR);
		ft_strdel((char **)&(lst->STR));
		if (*line == NULL)
			return (-1);
		return (1);
	}
	*line = ft_strnew(0);
	return (0);
}

static int		gnl_str_merge(char **s1, char *s2)
{
	char *temp;

	if (*s1 != NULL)
	{
		temp = ft_strjoin(*s1, s2);
		ft_strdel(s1);
		*s1 = temp;
	}
	else
		*s1 = ft_strdup(s2);
	if (*s1 == NULL)
		return (-1);
	return (0);
}

static int		gnl_read(char **line, char *newl, char *buff, t_list *lst)
{
	int red;

	while (newl == NULL)
	{
		ft_strclr(buff);
		red = read((lst->FD), buff, BUFF_SIZE);
		if (red == 0)
			break ;
		if (red == -1)
			return (-1);
		if (gnl_str_merge((char **)&(lst->STR), buff) == -1)
			return (-1);
		newl = ft_strchr(lst->STR, '\n');
	}
	*line = lst->STR;
	if (newl == NULL)
		return (gnl_last_line(line, lst));
	newl[0] = '\0';
	*line = ft_strdup(lst->STR);
	if (*line == NULL)
		return (-1);
	ft_strreplace((char **)&(lst->STR), ft_strdup(&newl[1]));
	if (lst->STR == NULL)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*alst;
	t_list			*lst;
	char			*buff;
	char			*newl;
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	lst = gnl_get_lst(fd, alst);
	if (lst == NULL)
		return (-1);
	if (alst == NULL)
		alst = lst;
	buff = ft_strnew(BUFF_SIZE);
	if (buff == NULL)
		return (-1);
	newl = ((lst->STR) == NULL) ? NULL : ft_strchr((lst->STR), '\n');
	ret = gnl_read(line, newl, buff, lst);
	ft_strdel(&buff);
	return (ret);
}
