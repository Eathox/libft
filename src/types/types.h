/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/21 19:32:21 by pholster      #+#    #+#                 */
/*   Updated: 2019/09/21 19:32:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef int8_t t_int8;
typedef int16_t t_int16;
typedef int32_t t_int32;
typedef int64_t t_int64;
typedef uint8_t t_uint8;
typedef uint16_t t_uint16;
typedef uint32_t t_uint32;
typedef uint64_t t_uint64;
typedef float t_float32;
typedef double t_float64;
typedef long double t_float128;

/*
** * Union used to read any type 1 byte at an time using the 'mem_byte' field
** * Or treat data as if it was a different type with out type-casting
*/
typedef union u_convert {
	t_int8 int8;
	t_int8 *int8_ptr;
	t_int16 int16;
	t_int16 *int16_ptr;
	t_int32 int32;
	t_int32 *int32_ptr;
	t_int64 int64;
	t_int64 *int64_ptr;
	t_uint8 uint8;
	t_uint8 *uint8_ptr;
	t_uint16 uint16;
	t_uint16 *uint16_ptr;
	t_uint32 uint32;
	t_uint32 *uint32_ptr;
	t_uint64 uint64;
	t_uint64 *uint64_ptr;
	t_float32 float32;
	t_float32 *float32_ptr;
	t_float64 float64;
	t_float64 *float64_ptr;
	t_float128 float128;
	t_float128 *float128_ptr;
	bool boolean;
	bool *boolean_ptr;
	void *mem;
	t_uint8 *mem_byte;
} t_convert;
