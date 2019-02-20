/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdsplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:22:38 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 10:29:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freeret(char ***arr)
{
	ft_strarrdel(arr);
	return (NULL);
}

char		**ft_strdsplit(const char *str, const char *delims)
{
	char			**arr;
	int				word;
	size_t			len;
	unsigned int	i;

	i = 0;
	word = 0;
	arr = ft_strarrnew((size_t)ft_wrddcount(str, delims));
	if (arr == NULL)
		return (NULL);
	while (str != NULL && str[i] != '\0')
	{
		if (ft_chrin(delims, str[i]) == FALSE)
		{
			len = ft_strdlen(&str[i], delims);
			arr[word] = ft_strndup(&str[i], len);
			if (arr[word] == NULL)
				return (freeret(&arr));
			word++;
			i += (len - 1);
		}
		i++;
	}
	return (arr);
}
