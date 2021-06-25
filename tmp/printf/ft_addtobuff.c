#include <unistd.h>

#include "ft/mem.h"

#include "printf.h"
#include "priv.h"

static bool	addtolst(t_info *info) {
	static	t_list	*prv;
	t_list			*new;

	new = ft_lstnew_dup(info->buff, PF_BUFF_SIZE);
	if (prv == NULL)
		info->buff_list = new;
	else
		ft_lstaddbck(&prv, new);
	prv = new;
	return (prv != NULL);
}

bool			ft_addtobuff(t_info *info, const char *str, size_t len) {
	bool	ret;
	size_t	fit;

	if ((len + info->buff_len) > PF_BUFF_SIZE)
	{
		fit = PF_BUFF_SIZE - info->buff_len;
		ft_memcpy(&info->buff[info->buff_len], str, fit);
		if (info->fd == -1)
			ret = addtolst(info);
		else
			ret = (write(info->fd, info->buff, PF_BUFF_SIZE) != -1);
		info->added += fit;
		info->buff_len = 0;
		ft_bzero(info->buff, PF_BUFF_SIZE);
		if (ret == false)
			return (false);
		return (ft_addtobuff(info, &str[fit], len - fit));
	}
	ft_memcpy(&info->buff[info->buff_len], str, len);
	info->buff_len += len;
	info->added += len;
	return (true);
}
