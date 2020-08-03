/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:22:38 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:38:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char.h"

#include "str.h"

char		**ft_strsplit(const char *str, char c) {
	char	**arr;
	char	cs[2];

	cs[0] = c;
	cs[1] = '\0';
	arr = ft_strdsplit(str, cs);
	return (arr);
}
