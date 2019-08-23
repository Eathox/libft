/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashmapadd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/23 16:42:24 by pholster      ########   odam.nl         */
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
	cr_assert(ft_hashmapadd(NULL, "hashmap_null", "value") == FALSE);
}

Test(hashmapadd, key_null, .signal = SIGSEGV) {
	t_hashmap	*tab;

	tab = ft_hashmapnew(5, &ft_hashsdbm);
	cr_assert(ft_hashmapadd(tab, NULL, "value") == FALSE);
}

Test(hashmapadd, value_null) {
	t_hashmap	*tab;

	tab = ft_hashmapnew(1, &ft_hashsdbm);
	cr_assert(ft_hashmapadd(tab, "value_null", NULL) == TRUE);
	cr_assert(tab->arr[0] != NULL);
	cr_assert(tab->arr[0]->next == NULL);
	cr_assert(tab->arr[0]->value == NULL);
	cr_assert_str_eq(tab->arr[0]->key, "value_null");
}

Test(hashmapadd, add3) {
	t_hashmap	*tab;

	tab = ft_hashmapnew(3, &test_hash);
	cr_assert(ft_hashmapadd(tab, "Key_0", "0") == TRUE);
	cr_assert(ft_hashmapadd(tab, "Key_1", "1") == TRUE);
	cr_assert(ft_hashmapadd(tab, "Key_2", "2") == TRUE);

	cr_assert(tab->arr[0] != NULL);
	cr_assert(tab->arr[0]->next == NULL);
	cr_assert_str_eq(tab->arr[0]->value, "0");
	cr_assert_str_eq(tab->arr[0]->key, "Key_0");

	cr_assert(tab->arr[1] != NULL);
	cr_assert(tab->arr[1]->next == NULL);
	cr_assert_str_eq(tab->arr[1]->value, "1");
	cr_assert_str_eq(tab->arr[1]->key, "Key_1");

	cr_assert(tab->arr[2] != NULL);
	cr_assert(tab->arr[2]->next == NULL);
	cr_assert_str_eq(tab->arr[2]->value, "2");
	cr_assert_str_eq(tab->arr[2]->key, "Key_2");
}

Test(hashmapadd, replace) {
	t_hashmap	*tab;

	tab = ft_hashmapnew(2, &test_hash);
	cr_assert(ft_hashmapadd(tab, "Key_0", "0") == TRUE);
	cr_assert(ft_hashmapadd(tab, "Key_0", "replaced") == TRUE);

	cr_assert(tab->arr[1] == NULL);
	cr_assert(tab->arr[0] != NULL);
	cr_assert(tab->arr[0]->next == NULL);
	cr_assert_str_eq(tab->arr[0]->value, "replaced");
	cr_assert_str_eq(tab->arr[0]->key, "Key_0");
}

Test(hashmapadd, replace_first) {
	t_hashmap	*tab;

	tab = ft_hashmapnew(2, &test_hash);
	cr_assert(ft_hashmapadd(tab, "Key_0", "0") == TRUE);
	cr_assert(ft_hashmapadd(tab, "Key_0", "replaced") == TRUE);
	cr_assert(ft_hashmapadd(tab, "last0", "Last") == TRUE);

	cr_assert(tab->arr[1] == NULL);
	cr_assert(tab->arr[0] != NULL);
	cr_assert(tab->arr[0]->next != NULL);
	cr_assert_str_eq(tab->arr[0]->value, "replaced");
	cr_assert_str_eq(tab->arr[0]->key, "Key_0");
	cr_assert_str_eq(tab->arr[0]->next->value, "Last");
	cr_assert_str_eq(tab->arr[0]->next->key, "last0");
}
