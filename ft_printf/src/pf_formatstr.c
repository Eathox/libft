/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatstr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:59:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

static void	formatstr(t_info *info)
{
	char	*str;
	ssize_t	n;

	str = va_arg(info->args, char *);
	n = info->precision;
	if (str == NULL)
		str = "(null)";
	if (n == -1)
		info->var_len = ft_strlen(str);
	else
		info->var_len = ft_strnlen(str, n);
	pf_formatpad(info);
	pf_addnstr(info, str, info->var_len);
}

static void	formatwchar(t_info *info)
{
	t_wchar	*str;
	ssize_t	n;

	str = va_arg(info->args, t_wchar *);
	n = info->precision;
	if (str == NULL)
		str = L"(null)";
	if (n == -1)
		info->var_len = ft_utf8strlen(str);
	else
		info->var_len = ft_utf8strnlen(str, n);
	pf_formatpad(info);
	pf_addwcharstr(info, str, info->var_len);
}

void		pf_formatstr(t_info *info)
{
	if (info->var_type == STR)
		formatstr(info);
	else
		formatwchar(info);
}