/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashdjb2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/22 12:06:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

Test(hashdjb2, str_null, .signal = SIGSEGV) {
	size_t	dex;

	dex = ft_hashdjb2(NULL, 4);
}

Test(hashdjb2, str_1) {
	size_t	dex;

	dex = ft_hashdjb2("1", 1);
	cr_assert(dex == 177622);
}

Test(hashdjb2, str_22) {
	size_t	dex;

	dex = ft_hashdjb2("22", 2);
	cr_assert(dex == 5861609);
}

Test(hashdjb2, str_str) {
	size_t	dex;

	dex = ft_hashdjb2("Str", 3);
	cr_assert(dex == 193471326);
}
