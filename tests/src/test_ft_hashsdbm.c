/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashsdbm.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 14:06:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

Test(hashsdbm, str_null, .signal = SIGSEGV) {
	size_t	dex;

	dex = ft_hashsdbm(NULL, 4);
}

Test(hashsdbm, str_1) {
	size_t	dex;

	dex = ft_hashsdbm("1", 1);
	cr_assert(dex == 49);
}

Test(hashsdbm, str_22) {
	size_t	dex;

	dex = ft_hashsdbm("22", 2);
	cr_assert(dex == 3280000);
}

Test(hashsdbm, str_str) {
	size_t	dex;

	dex = ft_hashsdbm("Str", 3);
	cr_assert(dex == 357175600081);
}
