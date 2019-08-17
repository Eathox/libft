/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_bzero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 15:59:22 by pholster       #+#    #+#                */
/*   Updated: 2019/08/17 17:28:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "unistd.h"
#include <criterion/criterion.h>

Test(bzero, str_null, .signal = SIGSEGV) {
	ft_bzero(NULL, 10);
}

Test(bzero, str_zero) {
	char	str[] = "hello world";

	ft_bzero(str, 0);
	cr_assert_str_eq(str, "hello world");
}

Test(bzero, str_term) {
	size_t	i = 0;
	char	tar[] = "\0\0\0\0\0bar";
	char	str[] = "foo\0 bar";

	bzero(str, 5);
	while (i < 9)
	{
		cr_assert(str[i] == tar[i]);
		i++;
	}
}

Test(bzero, num_half) {
	int		num;

	num = 0xFFFFFFFF;
	ft_bzero(&num, 2);
	cr_assert(num == 0xFFFF0000);
}