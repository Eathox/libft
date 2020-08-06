/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatdouble.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:27:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "ft/num.h"

#include "printf.h"
#include "priv.h"

static int	setdecimals(long double value, char *decimals, ssize_t n) {
	ssize_t	i;
	int		num;

	i = 0;
	num = 0;
	while (i < (n + 1))
	{
		value *= 10;
		num = (int)value;
		decimals[i] = num + '0';
		value -= num;
		i++;
	}
	i--;
	if (decimals[i] < '5')
		return (0);
	decimals[i] += 1;
	while (i >= 0 && decimals[i] == ('9' + 1))
	{
		decimals[i] = '0';
		i--;
		if (i != -1)
			decimals[i]++;
	}
	return (i == -1);
}

static void	adddouble(t_info *info, long double value, ssize_t n) {
	char		*decimals;
	intmax_t	num;

	decimals = ft_strnew(n + 1);
	if (decimals == NULL)
		return ;
	if (value < 0)
		value *= -1;
	num = (intmax_t)value;
	value -= num;
	num += setdecimals(value, decimals, n);
	if (n == 0 && decimals[0] >= '5')
		num++;
	ft_addnum(info, num);
	if (n != 0)
	{
		ft_addnstr(info, ".", 1);
		ft_addnstr(info, decimals, n);
	}
	ft_strdel(&decimals);
}

static void	formatdouble(t_info *info) {
	double	value;

	value = va_arg(info->args, double);
	info->var_len = ft_numlen((long)value) + info->precision;
	info->is_negative = (value < 0);
	info->is_zero = (value == 0);
	ft_formatpad(info);
	adddouble(info, value, info->precision);
}

static void	formatldouble(t_info *info) {
	long double	value;

	value = va_arg(info->args, long double);
	info->var_len = ft_numlen((long)value) + info->precision;
	info->is_negative = (value < 0);
	info->is_zero = (value == 0);
	ft_formatpad(info);
	adddouble(info, value, info->precision);
}

void		ft_formatdouble(t_info *info) {
	if (info->var_type == DOUBLE)
		formatdouble(info);
	else
		formatldouble(info);
}
