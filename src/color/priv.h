/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   priv.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 04:39:06 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/17 04:39:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIV_H
# define PRIV_H

# include "color.h"

/*
** * Convert a hex string color channel to t_uint8
*/
t_uint8		convert_hex_channel(
	char const *channel
);

#endif
