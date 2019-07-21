/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap(intmax_t *a, intmax_t *b)
{
	intmax_t	temp_a;

	temp_a = *a;
	*a = *b;
	*b = temp_a;
}
