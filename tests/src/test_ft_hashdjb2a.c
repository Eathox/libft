/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashdjb2a.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/22 15:36:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

Test(hashdjb2a, str_null, .signal = SIGSEGV) {
	size_t	dex;

	dex = ft_hashdjb2a(NULL);
}

Test(hashdjb2a, str_1) {
	size_t	dex;

	dex = ft_hashdjb2a("1");
	cr_assert(dex == 177556);
}

Test(hashdjb2a, str_22) {
	size_t	dex;

	dex = ft_hashdjb2a("22");
	cr_assert(dex == 5859397);
}

Test(hashdjb2a, str_str) {
	size_t	dex;

	dex = ft_hashdjb2a("Str");
	cr_assert(dex == 193465712);
}
