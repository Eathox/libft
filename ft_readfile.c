/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readfile.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 18:30:38 by pholster       #+#    #+#                */
/*   Updated: 2019/04/03 18:44:00 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_readfile(int fd)
{
	char	*str;
	char	buff[BUFF_SIZE + 1];
	int		ret;

	str = NULL;
	ft_bzero(buff, BUFF_SIZE + 1);
	ret = read(fd, buff, BUFF_SIZE);
	while (ret >= 0)
	{
		if (str == NULL)
			str = ft_strdup(buff);
		else
			ft_strreplace(&str, ft_strjoin(str, buff));
		if (ret == 0)
			break ;
		ft_strclr(buff);
		ret = read(fd, buff, BUFF_SIZE);
	}
	return (str);
}
