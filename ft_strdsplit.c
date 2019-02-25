/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdsplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:22:38 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:11:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freeret(char ***arr)
{
	ft_strarrdel(arr);
	return (NULL);
}

char		**ft_strdsplit(const char *str, const char *dlm)
{
	char	**arr;
	size_t	word;
	size_t	len;
	size_t	i;

	i = 0;
	word = 0;
	arr = ft_strarrnew(ft_wrddcount(str, dlm));
	if (arr == NULL || str == NULL)
		return (arr);
	while (str[i] != '\0')
	{
		if (ft_chrin(dlm, str[i]) == FALSE)
		{
			len = ft_strdlen(&str[i], dlm);
			arr[word] = ft_strndup(&str[i], len);
			if (arr[word] == NULL)
				return (freeret(&arr));
			i += (len - 1);
			word++;
		}
		i++;
	}
	return (arr);
}
