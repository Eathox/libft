/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashmapnew.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 13:00:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

static size_t	invalidf(const void *key)
{
	(void)key;
	return (0);
}

Test(hashmapnew, f_null) {
	t_hashmap	*map;

	map = ft_hashmapnew(5, NULL);
	cr_assert(map != NULL);
}

Test(hashmapnew, size_0) {
	t_hashmap	*map;

	map = ft_hashmapnew(0, &ft_hashsdbm);
	cr_assert(map != NULL);
}

Test(hashmapnew, f_invalid) {
	t_hashmap	*map;

	map = ft_hashmapnew(4, &invalidf);
	cr_assert(map != NULL);
	cr_assert(map->f == invalidf);
}

Test(hashmapnew, four) {
	t_hashlist	*tar[] = {0, 0, 0, 0};
	t_hashmap	*map;

	map = ft_hashmapnew(4, &ft_hashsdbm);
	cr_assert(map != NULL);
	cr_assert(map->f == &ft_hashsdbm);
	cr_assert(map->arr != NULL);
	cr_assert(map->size == 4);
	cr_assert_arr_eq(map->arr, tar, sizeof(tar));
}

Test(hashmapnew, fifty_eight) {
	t_hashlist	*tar[] = {0, 0, 0, 0};
	t_hashmap	*map;

	map = ft_hashmapnew(58, &ft_hashdjb2);
	cr_assert(map != NULL);
	cr_assert(map->f == &ft_hashdjb2);
	cr_assert(map->arr != NULL);
	cr_assert(map->size == 58);
	cr_assert_arr_eq(map->arr, tar, sizeof(tar));
}
