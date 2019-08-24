/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi_base.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 15:59:22 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 12:58:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>

Test(atoi_base, str_null, .signal = SIGSEGV) {
	ft_atoi_base(NULL, 10);
}

Test(atoi_base, whitespace_base_10) {
	cr_assert(ft_atoi_base(" \t\n\v\f\r", 10) == 0);
}

Test(atoi_base, empty_base_10) {
	cr_assert(ft_atoi_base("", 10) == 0);
}

Test(atoi_base, junk_base_10) {
	cr_assert(ft_atoi_base("asduiergjkfdvm", 10) == 0);
}

Test(atoi_base, junk_middle_base_10) {
	cr_assert(ft_atoi_base("404X10", 10) == 404);
}

Test(atoi_base, one_digit_base_10) {
	cr_assert(ft_atoi_base("5", 10) == 5);
}

Test(atoi_base, one_digit_base_0) {
	cr_assert(ft_atoi_base("5", 0) == 0);
}

Test(atoi_base, one_digit_base_42) {
	cr_assert(ft_atoi_base("5", 42) == 0);
}

Test(atoi_base, neg_one_digit_base_10) {
	cr_assert(ft_atoi_base("-5", 10) == -5);
}

Test(atoi_base, three_digit_base_2) {
	cr_assert(ft_atoi_base("1100101", 2) == 101);
}

Test(atoi_base, three_digit_base_10) {
	cr_assert(ft_atoi_base("123", 10) == 123);
}

Test(atoi_base, three_digit_base_16) {
	cr_assert(ft_atoi_base("1A4", 16) == 420);
}

Test(atoi_base, neg_three_digit_base_9) {
	cr_assert(ft_atoi_base("-288", 9) == 242);
}

Test(atoi_base, neg_three_digit_base_10) {
	cr_assert(ft_atoi_base("-152", 10) == -152);
}

Test(atoi_base, neg_three_digit_base_11) {
	cr_assert(ft_atoi_base("-272", 11) == 321);
}

Test(atoi_base, symmetrical_base_10) {
	cr_assert(ft_atoi_base("1001", 10) == 1001);
}

Test(atoi_base, zero_start_base_10) {
	cr_assert(ft_atoi_base("0004", 10) == 4);
}

Test(atoi_base, space_start_base_10) {
	cr_assert(ft_atoi_base("    1500000", 10) == 1500000);
}

Test(atoi_base, plus_base_10) {
	cr_assert(ft_atoi_base("+70", 10) == 70);
}

Test(atoi_base, plus_base_16) {
	cr_assert(ft_atoi_base("+15", 16) == 21);
}

Test(atoi_base, plus_minus_base_16) {
	cr_assert(ft_atoi_base("+-82", 16) == 0);
}

Test(atoi_base, minus_plus_base_10) {
	cr_assert(ft_atoi_base("- +82", 10) == 0);
}

Test(atoi_base, space_plus_start_base_10) {
	cr_assert(ft_atoi_base("    +999", 10) == 999);
}

Test(atoi_base, int_max_base_10) {
	cr_assert(ft_atoi_base("2147483647", 10) == INT_MAX);
}

Test(atoi_base, int_max_plus_base_10) {
	cr_assert(ft_atoi_base("2147483648", 10) == (intmax_t)INT_MAX + 1);
}

Test(atoi_base, long_max_base_10) {
	cr_assert(ft_atoi_base("9223372036854775807", 10) == INTMAX_MAX);
}

Test(atoi_base, long_max_plus_base_10) {
	cr_assert(ft_atoi_base("9223372036854775808", 10) == INTMAX_MAX);
}

Test(atoi_base, int_min_base_10) {
	cr_assert(ft_atoi_base("-2147483648", 10) == INT_MIN);
}

Test(atoi_base, int_min_minus_base_10) {
	cr_assert(ft_atoi_base("-2147483649", 10) == (intmax_t)INT_MIN - 1);
}

Test(atoi_base, long_min_base_10) {
	cr_assert(ft_atoi_base("-9223372036854775808", 10) == INTMAX_MIN);
}

Test(atoi_base, long_min_mins_base_10) {
	cr_assert(ft_atoi_base("-9223372036854775809", 10) == INTMAX_MIN);
}