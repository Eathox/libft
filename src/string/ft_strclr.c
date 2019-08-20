/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:58:39 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 19:46:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *str)
{
	ft_bzero(str, ft_strlen(str));
}
