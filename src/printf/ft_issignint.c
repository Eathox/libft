/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_issignint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 15:52:55 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "priv.h"

bool		ft_issignint(const t_info *info) {
	if (info->var_type == INT || info->var_type == MAX_INT)
		return (true);
	if (info->var_type == LONG || info->var_type == LONG_LONG)
		return (true);
	if (info->var_type == CHAR_I || info->var_type == SHORT)
		return (true);
	return (false);
}
