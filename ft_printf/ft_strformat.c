/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strformat.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/04/26 17:00:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// USE BUFFER AND WHEN USING FORMAT MAKE BUFFER JOIN INSTEAD OF PRINT WIP
// FIX ALL LEAKS WHEN CREATING STRINGS
// ADD VAR LEN POINTER

static char		*freeret(t_info *info, size_t *len)
{
	char	*str;

	str = PF_BUFF;
	if (len != NULL)
		*len = 0;
	if (info != NULL)
		free(info);
	return (str);
}

char			*ft_strformat(size_t *len, const char *format, ...)
{
	int		i;
	t_info	*info;

	i = 0;
	info = pf_infonew();
	if (info == NULL)
		return (NULL);
	PF_FD = -1;
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
	return (freeret(info, len));
}
