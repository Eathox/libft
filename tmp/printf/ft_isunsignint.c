/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isunsignint.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 15:52:53 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "priv.h"

bool	ft_isunsignint(const t_info *info) {
	if (info->var_type == U_INT || info->var_type == U_SHORT)
		return (true);
	if (info->var_type == MAX_U_INT || info->var_type == SIZE_T)
		return (true);
	if (info->var_type == U_LONG || info->var_type == U_LONG_LONG)
		return (true);
	if (info->var_type == U_CHAR_I || info->var_type == VOID)
		return (true);
	return (false);
}
