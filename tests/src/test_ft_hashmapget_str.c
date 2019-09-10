/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashmapget_str.c                               :+:    :+:            */
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

static size_t	test_hash(const void *key, size_t keysize)
{
	const char	*str = key;
	return (str[4] - '0');
}

Test(hashmapget_str, hashmap_null, .signal = SIGSEGV) {
	ft_hashmapget_str(NULL, "hashmap_null");
}

Test(hashmapget_str_str, key_null, .signal = SIGSEGV) {
	t_hashmap	*map;

	map = ft_hashmapnew(5, &ft_hashsdbm);
	ft_hashmapget_str(map, NULL);
}

Test(hashmapget_str, modhash) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	ft_hashmapadd_str(map, "Key_9", "9");

	cr_assert_str_eq(ft_hashmapget_str(map, "Key_9"), "9");
}

Test(hashmapget_str, first) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	ft_hashmapadd_str(map, "fir_0", "fir");
	ft_hashmapadd_str(map, "Key_2", "2");
	ft_hashmapadd_str(map, "mid_0", "mid");
	ft_hashmapadd_str(map, "Key_4", "4");
	ft_hashmapadd_str(map, "last0", "last");

	cr_assert_str_eq(ft_hashmapget_str(map, "fir_0"), "fir");
}

Test(hashmapget_str, middle) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	ft_hashmapadd_str(map, "fir_0", "fir");
	ft_hashmapadd_str(map, "Key_2", "2");
	ft_hashmapadd_str(map, "mid_0", "mid");
	ft_hashmapadd_str(map, "Key_4", "4");
	ft_hashmapadd_str(map, "last0", "last");

	cr_assert_str_eq(ft_hashmapget_str(map, "mid_0"), "mid");
}

Test(hashmapget_str, last) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	ft_hashmapadd_str(map, "fir_0", "fir");
	ft_hashmapadd_str(map, "Key_2", "2");
	ft_hashmapadd_str(map, "mid_0", "mid");
	ft_hashmapadd_str(map, "Key_4", "4");
	ft_hashmapadd_str(map, "last0", "last");

	cr_assert_str_eq(ft_hashmapget_str(map, "last0"), "last");
}
