/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getnextline.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:25:35 by pholster       #+#    #+#                */
/*   Updated: 2019/07/17 17:02:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

ssize_t		ft_getnextline(const int fd, char **line)
{
	return (ft_getnextdline(fd, line, '\n'));
}
