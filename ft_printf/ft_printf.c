/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:59:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		freeret(t_info *info)
{
	int	print_count;

	print_count = PF_PRINTED;
	if (info != NULL)
		free(info);
	return (print_count);
}

static int		distribute(va_list args, t_info *info, const char *start)
{
	int	i;

	if (*start == '{')
		i = pf_setcolor(&start[1]);
	else if (*start == '[')
		i = pf_commands(&start[1]);
	else
	{
		pf_infosetdefualt(info);
		i = pf_getinfo(args, info, start);
		pf_print(info);
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	int		i;
	t_info	*info;
	va_list	args;

	i = 0;
	info = pf_infonew();
	if (info == NULL)
		return (freeret(info));
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += distribute(args, info, &format[i + 1]);
		else
			i += pf_putstr(info, (char *)&format[i]);
		i++;
	}
	va_end(args);
	return (freeret(info));
}
