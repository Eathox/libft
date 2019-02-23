/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdsplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:22:38 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 00:00:34 by pholster      ########   odam.nl         */
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
	char			**arr;
	int				word;
	size_t			len;
	unsigned int	i;

	i = 0;
	word = 0;
	arr = ft_strarrnew((size_t)ft_wrddcount(str, dlm));
	if (arr == NULL)
		return (NULL);
	while (str != NULL && str[i] != '\0')
	{
		if (ft_chrin(dlm, str[i]) == FALSE)
		{
			len = ft_strdlen(&str[i], dlm);
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
