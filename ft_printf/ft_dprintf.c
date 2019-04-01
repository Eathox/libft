/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:34:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		freeret(t_info *info)
{
	int	print_count;

	print_count = PF_PRINTED;
	if (info != NULL)
		free(info);
	return (print_count);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	int		i;
	t_info	*info;
	va_list	args;

	i = 0;
	info = pf_infonew();
	PF_FD = fd;
	if (info == NULL)
		return (freeret(info));
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += pf_distribute(args, info, &format[i + 1]);
		else
			i += pf_putstr(info, (char *)&format[i]);
		i++;
	}
	va_end(args);
	return (freeret(info));
}
