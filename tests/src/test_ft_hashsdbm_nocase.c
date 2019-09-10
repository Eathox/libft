/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashsdbm_nocase.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 14:06:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

Test(hashsdbm_nocase, str_null, .signal = SIGSEGV) {
	size_t	dex;

	dex = ft_hashsdbm_nocase(NULL, 4);
}

Test(hashsdbm_nocase, str_1) {
	size_t	dex;

	dex = ft_hashsdbm_nocase("1", 1);
	cr_assert(dex == 49);
}

Test(hashsdbm_nocase, str_22) {
	size_t	dex;

	dex = ft_hashsdbm_nocase("22", 2);
	cr_assert(dex == 3280000);
}

Test(hashsdbm_nocase, str_str) {
	size_t	dex;

	dex = ft_hashsdbm_nocase("Str", 3);
	cr_assert(dex == 494878921713);
}
