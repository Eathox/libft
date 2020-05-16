/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unum.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:49:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNUM_H
# define FT_UNUM_H

# include <string.h>
# include <stdint.h>
# include <stdbool.h>

size_t		ft_unumlen_base(uintmax_t value, int base);
size_t		ft_unumlen(uintmax_t value);
bool		ft_putunum_base_fd(uintmax_t value, int base, int fd);
bool		ft_putunum_base(uintmax_t value, int base);
bool		ft_putunum_cbase_fd(uintmax_t value, int base, bool up, int fd);
bool		ft_putunum_cbase(uintmax_t value, int base, bool up);
bool		ft_putunum_fd(uintmax_t value, int fd);
bool		ft_putunum(uintmax_t value);

#endif
