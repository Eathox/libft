/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 23:47:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUM_H
# define FT_NUM_H

long double	ft_max(
	long double num1,
	long double num2
);

long double	ft_min(
	long double num1,
	long double num2
);

long double	ft_clamp(
	long double value,
	long double max,
	long double min
);

long double	ft_overflow(
	long double value,
	long double max,
	long double min
);

long double	ft_normalize(
	long double value,
	long double const *range,
	long double const *outrange
);

long double	ft_nearestnum(
	long double value,
	long double num1,
	long double num2
);

#endif
