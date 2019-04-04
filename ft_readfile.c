/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readfile.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 18:30:38 by pholster       #+#    #+#                */
/*   Updated: 2019/04/04 12:02:21 by pholster      ########   odam.nl         */
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
		if (str == NULL)
			return (NULL);
		if (ret == 0)
			break ;
		ft_strclr(buff);
		ret = read(fd, buff, BUFF_SIZE);
	}
	return (str);
}
