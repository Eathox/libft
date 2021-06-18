/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdel_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:08:14 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../types/types.h"
#include "mem.h"

#define LEN 8

Test(ft_memdel, null) {
	ft_memdel(NULL);
}

Test(ft_memdel, null_content) {
	void	*mem;

	mem = NULL;
	ft_memdel(&mem);
	cr_assert_eq(mem, NULL);
}

Test(ft_memdel, memory) {
	void	*mem;

	mem = malloc(LEN);
	cr_expect_neq(mem, NULL);

	ft_memdel(&mem);
	cr_assert_eq(mem, NULL);
}

Test(ft_memdel, stack, .signal = SIGABRT) {
	t_uint8	mem[LEN];

	cr_redirect_stderr();
	ft_memdel((void**)&mem);
}
