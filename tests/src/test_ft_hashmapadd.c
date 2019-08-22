/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashmapadd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 19:21:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

Test(hashmapadd, hashmap_null, .signal = SIGSEGV) {
	cr_assert(ft_hashmapadd(NULL, "hashmap_null") == FALSE);
}

Test(hashmapadd, key_null, .signal = SIGSEGV) {
	t_hashmap	*tab;

	tab = ft_hashmapnew(5, &ft_hashsdbm);
	cr_assert(ft_hashmapadd(tab, NULL) == FALSE);
}
