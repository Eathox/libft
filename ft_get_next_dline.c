/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_dline.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:25:35 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 14:22:20 by pholster      ########   odam.nl         */
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

static int		gnl_str_merge(char **str1, char *str2)
{
	if (*str1 != NULL)
		ft_strappend(str1, str2);
	else
		*str1 = ft_strdup(str2);
	if (*str1 == NULL)
		return (-1);
	return (0);
}

static int		gnl_read(char **line, char *buff, t_list *lst,
															const char *delims)
{
	int		red;
	int		newl;

	newl = ft_chrdindex((lst->STR), delims);
	while (newl == -1)
	{
		ft_strclr(buff);
		red = (int)read((int)(lst->FD), buff, BUFF_SIZE);
		if (red == 0)
			break ;
		if (red == -1 || gnl_str_merge((char **)&(lst->STR), buff) == -1)
			return (-1);
		newl = ft_chrdindex(lst->STR, delims);
	}
	*line = lst->STR;
	if (newl == -1)
		return (gnl_last_line(line, lst));
	((char *)lst->STR)[newl] = '\0';
	*line = ft_strdup(lst->STR);
	if (*line == NULL)
		return (-1);
	ft_strreplace((char **)&(lst->STR), ft_strdup(&lst->STR[newl + 1]));
	if (lst->STR == NULL)
		return (-1);
	return (1);
}

int				get_next_dline(const int fd, char **line, const char *delims)
{
	static t_list	*alst;
	t_list			*lst;
	char			*buff;
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
	ret = gnl_read(line, buff, lst, delims);
	ft_strdel(&buff);
	return (ret);
}
