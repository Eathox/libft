/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:03:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"
#include "ft/mem.h"
#include "ft/str.h"

ssize_t		ft_chrindex(const char *str, char c)
{
	return (ft_memindex(str, c, ft_strlen(str)));
}
