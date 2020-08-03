/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pututf8str_fd.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:51:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

#include "utf8.h"

bool	ft_pututf8str_fd(const t_wchar *str, int fd) {
	size_t	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr_fd("(null)", fd));
	while (str[i] != '\0') {
		if (ft_pututf8_fd(str[i], fd) == false)
			return (false);
		i++;
	}
	return (true);
}
