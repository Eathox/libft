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
Test(types, int8_t_size) {
	cr_assert_eq(sizeof(int8_t), 1);
	cr_assert_eq(sizeof(int8_t), sizeof(char));
}

Test(types, int16_t_size) {
	cr_assert_eq(sizeof(int16_t), 2);
	cr_assert_eq(sizeof(int16_t), sizeof(short));
}

Test(types, int32_t_size) {
	cr_assert_eq(sizeof(int32_t), 4);
	cr_assert_eq(sizeof(int32_t), sizeof(int));
}

Test(types, int64_t_size) {
	cr_assert_eq(sizeof(int64_t), 8);
	cr_assert_eq(sizeof(int64_t), sizeof(long int));
}

/*
** * Unsigned
*/
Test(types, uint8_t_size) {
	cr_assert_eq(sizeof(uint8_t), 1);
	cr_assert_eq(sizeof(uint8_t), sizeof(unsigned char));
}

Test(types, uint16_t_size) {
	cr_assert_eq(sizeof(uint16_t), 2);
	cr_assert_eq(sizeof(uint16_t), sizeof(unsigned short));
}

Test(types, uint32_t_size) {
	cr_assert_eq(sizeof(uint32_t), 4);
	cr_assert_eq(sizeof(uint32_t), sizeof(unsigned int));
}

Test(types, uint64_t_size) {
	cr_assert_eq(sizeof(uint64_t), 8);
	cr_assert_eq(sizeof(uint64_t), sizeof(unsigned long int));
}

/*
** * Float
*/
Test(types, float32_t_size) {
	cr_assert_eq(sizeof(float32_t), 4);
	cr_assert_eq(sizeof(float32_t), sizeof(float));
}

Test(types, float64_t_size) {
	cr_assert_eq(sizeof(float64_t), 8);
	cr_assert_eq(sizeof(float64_t), sizeof(double));
}

Test(types, float128_t_size) {
	cr_assert_eq(sizeof(float128_t), 16);
	cr_assert_eq(sizeof(float128_t), sizeof(long double));
}
