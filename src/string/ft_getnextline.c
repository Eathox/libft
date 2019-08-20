/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getnextline.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:25:35 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_getnextline(int fd, char **line)
{
	return (ft_getnextdline(fd, line, '\n'));
}
