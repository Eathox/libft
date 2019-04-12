/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strformat.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/04/12 14:23:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//USE BUFFER AND WHEN USING FORMAT MAKE BUFFER JOIN INSTEAD OF PRINT WIP

static char		*freeret(t_info *info)
{
	char	*str;

	str = ft_strjoin_lst(PF_HEAD);
	if (info != NULL)
	{
		ft_lstdel(&PF_HEAD, &ft_lstdelmem);
		free(info);
	}
	return (str);
}

char			*ft_strformat(const char *format, ...)
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
