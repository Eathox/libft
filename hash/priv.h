/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   priv.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 17:51:50 by pholster       #+#    #+#                */
/*   Updated: 2020/02/15 17:51:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRIV_H
# define FT_PRIV_H

# include "ft/bool.h"
# include "ft/hash.h"

t_bool			ft_keyequ(const t_hashlist *entry, const void *key,
					size_t keysize);

#endif
