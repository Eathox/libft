/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strformat_len.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:25:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/printf.h"
#include "priv.h"
#include "ft/str.h"
#include "ft/mem.h"

static char		*joinlst(t_info *info)
{
	size_t	i;
	char	*str;
	t_list	*lst;

	i = 0;
	lst = info->buff_list;
	str = ft_strnew(info->added);
	if (str == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->content != NULL)
			ft_memcpy(&str[i], lst->content, lst->content_size);
		i += lst->content_size;
		lst = lst->next;
	}
	if (info->buff_len != 0)
		ft_memcpy(&str[i], info->buff, info->buff_len);
	return (str);
}

static char		*freeret(t_info *info)
{
	char	*str;

	if (info->buff_len == info->added)
	{
		str = ft_strnew(info->added);
		if (str == NULL)
			return (NULL);
		ft_memcpy(str, info->buff, info->added);
	}
	else
		str = joinlst(info);
	ft_lstdel(&info->buff_list, &ft_lstdelmem);
	if (info != NULL)
	{
		ft_strdel(&info->buff);
		free(info);
	}
	return (str);
}

char			*ft_strformat_len(size_t *len, const char *format, ...)
{
	size_t	i;
	t_info	*info;

	i = 0;
	info = ft_infonew();
	if (info == NULL)
		return (NULL);
	info->fd = -1;
	va_start(info->args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += ft_distribute(info, &format[i + 1]);
		else
			i += ft_addstr(info, &format[i]);
		i++;
	}
	va_end(info->args);
	if (len != NULL)
		*len = info->added;
	return (freeret(info));
}
