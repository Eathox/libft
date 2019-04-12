/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:34:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		freeret(t_info *info)
{
	int		len;
	char	*str;

	str = ft_strjoin_lst(PF_HEAD);
	if (info != NULL)
	{
		ft_lstdel(&PF_HEAD, &ft_lstdelmem);
		free(info);
	}
	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	ft_strdel(&str);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	int		i;
	t_info	*info;

	i = 0;
	info = pf_infonew();
	if (info == NULL)
		return (freeret(info));
	va_start(PF_ARGS, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += pf_distribute(info, &format[i + 1]);
		else
			i += pf_addstr(info, (char *)&format[i]);
		i++;
	}
	va_end(PF_ARGS);
	return (freeret(info));
}
