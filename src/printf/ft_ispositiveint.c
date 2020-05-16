/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ispositiveint.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 19:21:03 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "priv.h"

bool	ft_ispositiveint(const t_info *info)
{
	return (ft_issignint(info) && info->is_negative == false);
}
