/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_bzero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 15:59:22 by pholster       #+#    #+#                */
/*   Updated: 2019/08/18 14:28:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <signal.h>
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
	char	tar[] = "\0\0\0\0\0bar";
	char	str[] = "foo\0 bar";

	bzero(str, 5);
	cr_assert_arr_eq(str, tar, sizeof(tar));
}

Test(bzero, num_half) {
	int		num;

	num = 0xFFFFFFFF;
	ft_bzero(&num, 2);
	cr_assert(num == 0xFFFF0000);
}

Test(bzero, arr_big) {
	long	tar[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	long	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
	1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	ft_bzero(&arr, sizeof(arr));
	cr_assert_arr_eq(arr, tar, sizeof(tar));
}