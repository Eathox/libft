/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strformat.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:59:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

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
	return (str);
}

static char		*freeret(t_info *info)
{
	t_list	*lst;
	char	*str;

	if (info->buff_len != 0 && info->buff_len != info->added)
	{
		lst = ft_lstnew(NULL, 0);
		if (lst == NULL)
			return (NULL);
		lst->content = info->buff;
		lst->content_size = info->buff_len;
		ft_lstaddbck(&info->buff_list, lst);
	}
	if (info->buff_len == info->added)
		str = ft_memdup(info->buff, info->added);
	else
		str = joinlst(info);
	ft_lstdel(&info->buff_list, &ft_lstdelmem);
	if (info != NULL)
	{
		if (info->buff != NULL)
			free(info->buff);
		free(info);
	}
	return (str);
}

char			*ft_strformat(const char *format, ...)
{
	size_t	i;
	t_info	*info;

	i = 0;
	if (format == NULL)
		return (NULL);
	info = pf_infonew();
	if (info == NULL)
		return (NULL);
	info->fd = -1;
	va_start(info->args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += pf_distribute(info, &format[i + 1]);
		else
			i += pf_addstr(info, (char *)&format[i]);
		i++;
	}
	va_end(info->args);
	return (freeret(info));
}
