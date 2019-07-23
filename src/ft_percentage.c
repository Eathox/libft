/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_percentage.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:24:50 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:18:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

intmax_t	ft_percentage(intmax_t num, intmax_t centage)
{
	return ((num * centage) / 100);
}
