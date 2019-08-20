/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashdjb_nocase.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 14:05:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

Test(hashdjb_nocase, str_null, .signal = SIGSEGV) {
	size_t	dex;

	dex = ft_hashdjb_nocase(NULL);
}

Test(hashdjb_nocase, str_1) {
	size_t	dex;

	dex = ft_hashdjb_nocase("1");
	cr_assert(dex == 177622);
}

Test(hashdjb_nocase, str_22) {
	size_t	dex;

	dex = ft_hashdjb_nocase("22");
	cr_assert(dex == 5861609);
}

Test(hashdjb_nocase, str_str) {
	size_t	dex;

	dex = ft_hashdjb_nocase("Str");
	cr_assert(dex == 193506174);
}
