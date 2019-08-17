/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_abs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 15:12:17 by pholster       #+#    #+#                */
/*   Updated: 2019/08/16 15:52:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <criterion/criterion.h>
#include <limits.h>

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

Test(abs, intmax_min) {
    cr_assert(ft_abs((int)INTMAX_MIN) == abs((int)INTMAX_MIN));
}

Test(abs, intmax_max) {
    cr_assert(ft_abs((int)INTMAX_MAX) == abs((int)INTMAX_MAX));
}