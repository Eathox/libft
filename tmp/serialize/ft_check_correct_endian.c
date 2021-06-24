/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_correct_endian.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 20:16:00 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/04 20:16:00 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.h"
#include "priv.h"

bool		ft_check_correct_endian(t_serialize *serialize, size_t size) {
	if (ft_valid_endian(serialize->endian) == false ||
		ft_valid_endian(serialize->target_endian) == false)
		return (false);
	if (size <= 1)
		return (false);
	return (serialize->endian != serialize->target_endian);
}
