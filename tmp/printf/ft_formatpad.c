#include "ft/char.h"
#include "ft/str.h"
#include "ft/num.h"

#include "printf.h"
#include "priv.h"

static size_t	addprefix(t_info *info, char *str, size_t n) {
	if (n == 0)
		return (0);
	ft_addnstr(info, str, n);
	if (info->var_type == VOID && info->width <= info->precision)
		return (0);
	if (info->precision > info->width && ft_strequ(str, "0") == false)
		return (0);
	return (n);
}

static void		addpad(t_info *info, intmax_t len, char c) {
	intmax_t	i;

	i = 0;
	while (i < len)
	{
		ft_addtobuff(info, &c, 1);
		i++;
	}
}

static void		addzero(t_info *info, intmax_t len, intmax_t space, char *prfx) {
	size_t	prelen;
	char	c;

	prelen = ft_strlen(prfx);
	c = (ft_iszeropad(info)) ? '0' : ' ';
	len = len - ft_max(0, space);
	if (info->var_type == VOID || info->is_zero == false)
		len -= addprefix(info, prfx, prelen);
	else if (ft_strequ_nocase(prfx, "0x") == false && info->type != 'o')
		len -= addprefix(info, prfx, prelen);
	if (len > 0 && (PF_FLAG_MIN == false || c != ' '))
		addpad(info, len, c);
}

static char		*getprefix(t_info *info) {
	if (info->is_negative)
		return ("-");
	if (PF_FLAG_PLUS && ft_ispositiveint(info))
		return ("+");
	if (PF_FLAG_SPACE && ft_ispositiveint(info))
		return (" ");
	if ((PF_FLAG_HASH && ft_chrin("xX", info->type))
		|| info->var_type == VOID)
		return ((info->type == 'X') ? "0X" : "0x");
	if (PF_FLAG_HASH && info->type == 'o' && info->is_zero == false &&
		info->precision <= info->var_len)
		return ("0");
	return ("");
}

void			ft_formatpad(t_info *info) {
	char		*prfx;
	size_t		prelen;
	intmax_t	len;
	intmax_t	space;

	prfx = getprefix(info);
	prelen = ft_strlen(prfx);
	info->padadded = info->added;
	if (info->precision > info->width && ft_isstr(info) == false)
		len = ft_max(0, info->precision) - info->var_len;
	else
		len = ft_max(0, info->width) - info->var_len;
	space = ft_max(0, info->width) - ft_max(info->var_len, info->precision);
	if (info->var_type == VOID || info->is_zero == false)
		space -= prelen;
	else if (ft_strequ_nocase(prfx, "0x") == false && info->type != 'o')
		space -= prelen;
	if (PF_FLAG_ZERO && (info->precision == -1 ||
		(info->precision == 0 && PF_FLAG_HASH == false)))
		space = 0;
	if (space > 0 && PF_FLAG_MIN == false)
		addpad(info, space, ' ');
	addzero(info, len, space, prfx);
	info->padadded = info->added - info->padadded;
}
