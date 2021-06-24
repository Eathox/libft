/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   term.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:01:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include <stdbool.h>

# include "ft/color.h"

bool		ft_termclr(void);
bool		ft_termclr_fd(int fd);
bool		ft_termcommand(int command);
bool		ft_termcommand_fd(int command, int fd);
bool		ft_termresetcolor(void);
bool		ft_termresetcolor_fd(int fd);
bool		ft_termresetcolorbg(void);
bool		ft_termresetcolorbg_fd(int fd);
bool		ft_termsetcolor(t_uint8 color);
bool		ft_termsetcolor_fd(t_uint8 color, int fd);
bool		ft_termsetcolorbg(t_uint8 color);
bool		ft_termsetcolorbg_fd(t_uint8 color, int fd);
bool		ft_termsetrgbcolor(t_color rgb);
bool		ft_termsetrgbcolor_fd(t_color rgb, int fd);
bool		ft_termsetrgbcolorbg(t_color rgb);
bool		ft_termsetrgbcolorbg_fd(t_color rgb, int fd);

#endif
