/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_hashmapnew.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:57:19 by pholster       #+#    #+#                */
/*   Updated: 2019/08/23 16:11:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <criterion/criterion.h>

static size_t	invalidf(char *str)
{
	(void)str;
	return (0);
}

Test(hashmapnew, f_null) {
	t_hashmap	*tab;

	tab = ft_hashmapnew(5, NULL);
	cr_assert(tab != NULL);
}

Test(hashmapnew, size_0) {
	t_hashmap	*tab;

	tab = ft_hashmapnew(0, &ft_hashsdbm);
	cr_assert(tab != NULL);
}

Test(hashmapnew, f_invalid) {
	t_hashmap	*tab;

	tab = ft_hashmapnew(4, &invalidf);
	cr_assert(tab != NULL);
	cr_assert(tab->f == invalidf);
}

Test(hashmapnew, four) {
	t_hashlist	*tar[] = {0, 0, 0, 0};
	t_hashmap	*tab;

	tab = ft_hashmapnew(4, &ft_hashsdbm);
	cr_assert(tab != NULL);
	cr_assert(tab->f == &ft_hashsdbm);
	cr_assert(tab->arr != NULL);
	cr_assert(tab->size == 4);
	cr_assert_arr_eq(tab->arr, tar, sizeof(tar));
}

Test(hashmapnew, fifty_eight) {
	t_hashlist	*tar[] = {0, 0, 0, 0};
	t_hashmap	*tab;

	tab = ft_hashmapnew(58, &ft_hashdjb2);
	cr_assert(tab != NULL);
	cr_assert(tab->f == &ft_hashdjb2);
	cr_assert(tab->arr != NULL);
	cr_assert(tab->size == 58);
	cr_assert_arr_eq(tab->arr, tar, sizeof(tar));
}
