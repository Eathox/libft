/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatstr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 16:54:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	formatstr(t_info *info)
{
	char	*str;
	ssize_t	n;

	str = va_arg(PF_ARGS, char *);
	n = PF_PRECISION;
	if (str == NULL)
		str = "(null)";
	if (n == -1)
		PF_VAR_LEN = ft_strlen(str);
	else
		PF_VAR_LEN = ft_strnlen(str, n);
	pf_formatpad(info);
	pf_addnstr(info, str, PF_VAR_LEN);
}

static void	formatwchar(t_info *info)
{
	t_wchar	*str;
	ssize_t	n;

	str = va_arg(PF_ARGS, t_wchar *);
	n = PF_PRECISION;
	if (str == NULL)
		str = L"(null)";
	if (n == -1)
		PF_VAR_LEN = ft_utf8strlen(str);
	else
		PF_VAR_LEN = ft_utf8strnlen(str, n);
	pf_formatpad(info);
	pf_addwcharstr(info, str, PF_VAR_LEN);
}

void		pf_formatstr(t_info *info)
{
	if (PF_VAR_TYPE == STR)
		formatstr(info);
	else
		formatwchar(info);
}
