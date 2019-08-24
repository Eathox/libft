/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashmapget.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 12:56:09 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 13:10:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

static size_t	test_hash(char *key)
{
	return (key[4] - '0');
}

Test(hashmapget, hashmap_null, .signal = SIGSEGV) {
	ft_hashmapget(NULL, "hashmap_null");
}

Test(hashmapget, key_null, .signal = SIGSEGV) {
	t_hashmap	*map;

	map = ft_hashmapnew(5, &ft_hashsdbm);
	ft_hashmapget(map, NULL);
}

Test(hashmapget, modhash) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	ft_hashmapadd(map, "Key_9", "9");

	cr_assert_str_eq(ft_hashmapget(map, "Key_9"), "9");
}

Test(hashmapget, first) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	ft_hashmapadd(map, "fir_0", "fir");
	ft_hashmapadd(map, "Key_2", "2");
	ft_hashmapadd(map, "mid_0", "mid");
	ft_hashmapadd(map, "Key_4", "4");
	ft_hashmapadd(map, "last0", "last");

	cr_assert_str_eq(ft_hashmapget(map, "fir_0"), "fir");
}

Test(hashmapget, middle) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	ft_hashmapadd(map, "fir_0", "fir");
	ft_hashmapadd(map, "Key_2", "2");
	ft_hashmapadd(map, "mid_0", "mid");
	ft_hashmapadd(map, "Key_4", "4");
	ft_hashmapadd(map, "last0", "last");

	cr_assert_str_eq(ft_hashmapget(map, "mid_0"), "mid");
}

Test(hashmapget, last) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	ft_hashmapadd(map, "fir_0", "fir");
	ft_hashmapadd(map, "Key_2", "2");
	ft_hashmapadd(map, "mid_0", "mid");
	ft_hashmapadd(map, "Key_4", "4");
	ft_hashmapadd(map, "last0", "last");

	cr_assert_str_eq(ft_hashmapget(map, "last0"), "last");
}
