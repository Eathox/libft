/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashdjb2_nocase.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/22 12:06:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

Test(hashdjb2_nocase, str_null, .signal = SIGSEGV) {
	size_t	dex;

	dex = ft_hashdjb2_nocase(NULL, 4);
}

Test(hashdjb2_nocase, str_1) {
	size_t	dex;

	dex = ft_hashdjb2_nocase("1", 1);
	cr_assert(dex == 177622);
}

Test(hashdjb2_nocase, str_22) {
	size_t	dex;

	dex = ft_hashdjb2_nocase("22", 2);
	cr_assert(dex == 5861609);
}

Test(hashdjb2_nocase, str_str) {
	size_t	dex;

	dex = ft_hashdjb2_nocase("Str", 3);
	cr_assert(dex == 193506174);
}
