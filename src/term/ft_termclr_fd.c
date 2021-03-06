/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termclr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 14:51:28 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:41:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

#include "term.h"

bool	ft_termclr_fd(int fd) {
	return (ft_putstr_fd("\033[1;1H\033[2J\n", fd));
}
