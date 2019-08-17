/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi_base.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 15:59:22 by pholster       #+#    #+#                */
/*   Updated: 2019/08/17 16:43:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <criterion/criterion.h>

Test(atoi_base, str_null, .signal = SIGSEGV) {
	cr_assert(ft_atoi_base(NULL, 10) == 0);
}

Test(atoi_base, empty_base_0) {
	cr_assert(ft_atoi_base("", 0) == 0);
}

Test(atoi_base, empty_base_10) {
	cr_assert(ft_atoi_base("", 10) == 0);
}

Test(atoi_base, empty_base_42) {
	cr_assert(ft_atoi_base("", 42) == 0);
}

Test(atoi_base, whitespace_base_0) {
	cr_assert(ft_atoi_base(" \t\n\v\f\r", 0) == 0);
}

Test(atoi_base, whitespace_base_10) {
	cr_assert(ft_atoi_base(" \t\n\v\f\r", 10) == 0);
}

Test(atoi_base, whitespace_base_42) {
	cr_assert(ft_atoi_base(" \t\n\v\f\r", 42) == 0);
}

Test(atoi_base, junk_base_0) {
	cr_assert(ft_atoi_base("asduiergjkfdvm", 0) == 0);
}

Test(atoi_base, junk_base_10) {
	cr_assert(ft_atoi_base("asduiergjkfdvm", 10) == 0);
}

Test(atoi_base, junk_base_42) {
	cr_assert(ft_atoi_base("asduiergjkfdvm", 42) == 0);
}

Test(atoi_base, onedigit_base_0) {
	cr_assert(ft_atoi_base("5", 0) == 0);
}

Test(atoi_base, onedigit_base_10) {
	cr_assert(ft_atoi_base("5", 10) == 5);
}

Test(atoi_base, onedigit_base_42) {
	cr_assert(ft_atoi_base("5", 42) == 0);
}

Test(atoi_base, neg_onedigit_base_0) {
	cr_assert(ft_atoi_base("-5", 0) == 0);
}

Test(atoi_base, neg_onedigit_base_10) {
	cr_assert(ft_atoi_base("-5", 10) == -5);
}

Test(atoi_base, neg_onedigit_base_42) {
	cr_assert(ft_atoi_base("-5", 42) == 0);
}

Test(atoi_base, threedigit_base_0) {
	cr_assert(ft_atoi_base("123", 0) == 0);
}

Test(atoi_base, threedigit_base_10) {
	cr_assert(ft_atoi_base("123", 10) == 123);
}

Test(atoi_base, threedigit_base_42) {
	cr_assert(ft_atoi_base("123", 42) == 0);
}

Test(atoi_base, neg_threedigit_base_0) {
	cr_assert(ft_atoi_base("-123", 0) == 0);
}

Test(atoi_base, neg_threedigit_base_10) {
	cr_assert(ft_atoi_base("-123", 10) == -123);
}

Test(atoi_base, neg_threedigit_base_42) {
	cr_assert(ft_atoi_base("-123", 42) == 0);
}
