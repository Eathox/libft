/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_abs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 15:12:17 by pholster       #+#    #+#                */
/*   Updated: 2019/08/17 19:26:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <criterion/criterion.h>

Test(abs, zero) {
    cr_assert(ft_abs(0) == 0);
}

Test(abs, positive) {
    cr_assert(ft_abs(42) == 42);
}

Test(abs, negative) {
    cr_assert(ft_abs(-42) == 42);
}

Test(abs, int_max) {
    cr_assert(ft_abs(INT_MAX) == INT_MAX);
}

Test(abs, int_max_minus) {
    cr_assert(ft_abs(INT_MAX - 1) == INT_MAX - 1);
}

Test(abs, int_max_plus) {
    cr_assert(ft_abs(INT_MAX + 1) == (intmax_t)INT_MAX + 1);
}

Test(abs, int_min) {
    cr_assert(ft_abs(INT_MIN) == -(intmax_t)INT_MIN);
}

Test(abs, int_min_minus) {
    cr_assert(ft_abs(INT_MIN - 1) == INT_MAX);
}

Test(abs, int_min_plus) {
    cr_assert(ft_abs(INT_MIN + 1) == INT_MAX);
}

Test(abs, long_max) {
    cr_assert(ft_abs(INTMAX_MAX) == INTMAX_MAX);
}

Test(abs, long_max_min_plus) {
    cr_assert(ft_abs(INTMAX_MIN + 1) == INTMAX_MAX);
}

Test(abs, long_max_min_minus) {
    cr_assert(ft_abs(INTMAX_MIN - 1) == INTMAX_MAX);
}

Test(abs, long_min) {
    cr_assert(ft_abs(INTMAX_MIN) == INTMAX_MIN);
}

Test(abs, long_min_minus) {
    cr_assert(ft_abs(INTMAX_MIN - 1) == INTMAX_MAX);
}

Test(abs, long_min_plus) {
    cr_assert(ft_abs(INTMAX_MIN + 1) == INTMAX_MAX);
}
