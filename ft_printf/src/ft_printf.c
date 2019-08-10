/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 15:43:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <unistd.h>

static ssize_t	freeret(t_info *info)
{
	ssize_t		ret;

	ret = (ssize_t)info->added;
	if (write(info->fd, info->buff, info->buff_len) == -1)
		ret = -1;
	if (info != NULL)
	{
		free(info->buff);
		free(info);
	}
	return (ret);
}

ssize_t			ft_printf(const char *format, ...)
{
	size_t	i;
	t_info	*info;

	i = 0;
	if (format == NULL)
		return (-1);
	info = pf_infonew();
	if (info == NULL)
		return (-1);
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