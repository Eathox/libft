/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashdjb.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 14:05:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

Test(hashdjb, str_null, .signal = SIGSEGV) {
	size_t	dex;

	dex = ft_hashdjb(NULL);
}

Test(hashdjb, str_1) {
	size_t	dex;

	dex = ft_hashdjb("1");
	cr_assert(dex == 177622);
}

Test(hashdjb, str_22) {
	size_t	dex;

	dex = ft_hashdjb("22");
	cr_assert(dex == 5861609);
}

Test(hashdjb, str_str) {
	size_t	dex;

	dex = ft_hashdjb("Str");
	cr_assert(dex == 193471326);
}
