/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 20:55:42 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 20:55:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>

#include "types.h"

/*
** * Signed
*/
Test(types, t_int8_size) {
	cr_assert_eq(sizeof(t_int8), 1);
}

Test(types, t_int16_size) {
	cr_assert_eq(sizeof(t_int16), 2);
}

Test(types, t_int32_size) {
	cr_assert_eq(sizeof(t_int32), 4);
}

Test(types, t_int64_size) {
	cr_assert_eq(sizeof(t_int64), 8);
}

/*
** * Unsigned
*/
Test(types, t_uint8_size) {
	cr_assert_eq(sizeof(t_uint8), 1);
}

Test(types, t_uint16_size) {
	cr_assert_eq(sizeof(t_uint16), 2);
}

Test(types, t_uint32_size) {
	cr_assert_eq(sizeof(t_uint32), 4);
}

Test(types, t_uint64_size) {
	cr_assert_eq(sizeof(t_uint64), 8);
}

/*
** * Float
*/
Test(types, t_float32_size) {
	cr_assert_eq(sizeof(t_float32), 4);
}

Test(types, t_float64_size) {
	cr_assert_eq(sizeof(t_float64), 8);
}

Test(types, t_float128_size) {
	cr_assert_eq(sizeof(t_float128), 16);
}
