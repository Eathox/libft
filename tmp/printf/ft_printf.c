#include <unistd.h>

#include "ft/str.h"

#include "printf.h"
#include "priv.h"

static ssize_t	freeret(t_info *info) {
	ssize_t		ret;

	ret = (ssize_t)info->added;
	if (write(info->fd, info->buff, info->buff_len) == -1)
		ret = -1;
	if (info != NULL)
	{
		ft_strdel(&info->buff);
		free(info);
	}
	return (ret);
}

ssize_t			ft_printf(const char *format, ...) {
	size_t	i;
	t_info	*info;

	i = 0;
	if (format == NULL)
		return (ft_putstr(NULL));
	info = ft_infonew();
	if (info == NULL)
		return (-1);
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
	return (freeret(info));
}
