/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashmapadd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 13:04:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

static size_t	test_hash(char *key)
{
	return (key[4] - '0');
}

Test(hashmapadd, hashmap_null, .signal = SIGSEGV) {
	ft_hashmapadd(NULL, "hashmap_null", "value");
}

Test(hashmapadd, key_null, .signal = SIGSEGV) {
	t_hashmap	*map;

	map = ft_hashmapnew(5, &ft_hashsdbm);
	ft_hashmapadd(map, NULL, "value");
}

Test(hashmapadd, value_null) {
	t_hashmap	*map;

	map = ft_hashmapnew(1, &ft_hashsdbm);
	cr_assert(ft_hashmapadd(map, "value_null", NULL) == TRUE);

	cr_assert(map->arr[0]->next == NULL);
	cr_assert(map->arr[0]->value == NULL);
	cr_assert_str_eq(map->arr[0]->key, "value_null");
}

Test(hashmapadd, modhash) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	cr_assert(ft_hashmapadd(map, "Key_0", "0") == TRUE);
	cr_assert(ft_hashmapadd(map, "Key_8", "8") == TRUE);

	cr_assert_str_eq(map->arr[0]->value, "0");
	cr_assert_str_eq(map->arr[0]->key, "Key_0");
	cr_assert_str_eq(map->arr[0]->next->value, "8");
	cr_assert_str_eq(map->arr[0]->next->key, "Key_8");
}

Test(hashmapadd, add3) {
	t_hashmap	*map;

	map = ft_hashmapnew(3, &test_hash);
	cr_assert(ft_hashmapadd(map, "Key_0", "0") == TRUE);
	cr_assert(ft_hashmapadd(map, "Key_1", "1") == TRUE);
	cr_assert(ft_hashmapadd(map, "Key_2", "2") == TRUE);

	cr_assert(map->arr[0]->next == NULL);
	cr_assert_str_eq(map->arr[0]->value, "0");
	cr_assert_str_eq(map->arr[0]->key, "Key_0");

	cr_assert(map->arr[1]->next == NULL);
	cr_assert_str_eq(map->arr[1]->value, "1");
	cr_assert_str_eq(map->arr[1]->key, "Key_1");

	cr_assert(map->arr[2]->next == NULL);
	cr_assert_str_eq(map->arr[2]->value, "2");
	cr_assert_str_eq(map->arr[2]->key, "Key_2");
}

Test(hashmapadd, replace) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	cr_assert(ft_hashmapadd(map, "Key_0", "0") == TRUE);
	cr_assert(ft_hashmapadd(map, "Key_0", "replaced") == TRUE);

	cr_assert(map->arr[0]->next == NULL);
	cr_assert_str_eq(map->arr[0]->value, "replaced");
	cr_assert_str_eq(map->arr[0]->key, "Key_0");
}

Test(hashmapadd, replace_first) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	cr_assert(ft_hashmapadd(map, "Key_0", "0") == TRUE);
	cr_assert(ft_hashmapadd(map, "Key_0", "replaced") == TRUE);
	cr_assert(ft_hashmapadd(map, "last0", "Last") == TRUE);

	cr_assert(map->arr[0]->next != NULL);
	cr_assert_str_eq(map->arr[0]->value, "replaced");
	cr_assert_str_eq(map->arr[0]->key, "Key_0");
	cr_assert_str_eq(map->arr[0]->next->value, "Last");
	cr_assert_str_eq(map->arr[0]->next->key, "last0");
}

Test(hashmapadd, replace_last) {
	t_hashmap	*map;

	map = ft_hashmapnew(2, &test_hash);
	cr_assert(ft_hashmapadd(map, "fir_0", "first") == TRUE);
	cr_assert(ft_hashmapadd(map, "Key_0", "0") == TRUE);
	cr_assert(ft_hashmapadd(map, "Key_0", "replaced") == TRUE);

	cr_assert(map->arr[0]->next != NULL);
	cr_assert_str_eq(map->arr[0]->value, "first");
	cr_assert_str_eq(map->arr[0]->key, "fir_0");
	cr_assert_str_eq(map->arr[0]->next->value, "replaced");
	cr_assert_str_eq(map->arr[0]->next->key, "Key_0");
}

Test(hashmapadd, free_key) {
	t_hashmap	*map;
	char		*key;

	key = (char *)malloc(sizeof(char) * 6);
	memcpy(key, "free0", 6);
	map = ft_hashmapnew(2, &test_hash);
	cr_assert(ft_hashmapadd(map, key, "free") == TRUE);
	cr_assert(ft_hashmapadd(map, "last0", "0") == TRUE);

	//Free and reuse that memory
	free(key);
	key = (char *)malloc(sizeof(char) * 6);
	bzero(key, 6);

	cr_assert(map->arr[0]->next != NULL);
	cr_assert_str_eq(map->arr[0]->value, "free");
	cr_assert_str_eq(map->arr[0]->key, "free0");
}


