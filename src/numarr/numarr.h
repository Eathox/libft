/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   numarr.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:59:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMARR_H
# define FT_NUMARR_H

# include <string.h>
# include <stdint.h>
# include <stdbool.h>

# include "ft/list.h"

bool		ft_putnumarr(const intmax_t *arr, size_t len);
t_list		*ft_numarrtolst(const intmax_t *arr, size_t len);
bool		ft_numarrsortac(intmax_t current, intmax_t num);
void		ft_numarrsort(intmax_t *arr,
				bool (*f)(intmax_t, intmax_t), size_t len);
void		ft_numarrsortrev(intmax_t *arr,
				bool (*f)(intmax_t, intmax_t), size_t len);

#endif
