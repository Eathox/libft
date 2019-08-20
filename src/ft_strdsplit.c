/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdsplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:22:38 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 14:21:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freeret(char ***arr)
{
	ft_strarrdel(arr);
	return (NULL);
}

static void	addword(char **arr, char *str, size_t *word)
{
	arr[*word] = str;
	*word += 1;
}

char		**ft_strdsplit(char *str, char *dlm)
{
	char		**arr;
	long long	bytes[2];
	size_t		word;
	size_t		len;
	size_t		i;

	i = 0;
	word = 0;
	arr = ft_strarrnew(ft_wrddcount(str, dlm));
	if (arr == NULL)
		return (freeret(&arr));
	ft_chrsetbytes(bytes, dlm);
	while (str[i] != '\0')
	{
		if (ft_chrinbytes(bytes, str[i]) == FALSE)
		{
			len = ft_strdlen(&str[i], dlm);
			addword(arr, ft_strndup(&str[i], len), &word);
			if (arr[word - 1] == NULL)
				return (freeret(&arr));
			i += (len - 1);
		}
		i++;
	}
	return (arr);
}
