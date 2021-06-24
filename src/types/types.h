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

typedef float float32_t;
typedef double float64_t;
typedef long double float128_t;

/*
** * Union used to read any type 1 byte at an time using the 'mem_byte' field
** * Or treat data as if it was a different type with out type-casting
*/
typedef union convert_u {
	int8_t int8;
	int8_t *int8_ptr;
	int16_t int16;
	int16_t *int16_ptr;
	int32_t int32;
	int32_t *int32_ptr;
	int64_t int64;
	int64_t *int64_ptr;
	uint8_t uint8;
	uint8_t *uint8_ptr;
	uint16_t uint16;
	uint16_t *uint16_ptr;
	uint32_t uint32;
	uint32_t *uint32_ptr;
	uint64_t uint64;
	uint64_t *uint64_ptr;
	float32_t float32;
	float32_t *float32_ptr;
	float64_t float64;
	float64_t *float64_ptr;
	float128_t float128;
	float128_t *float128_ptr;
	bool boolean;
	bool *boolean_ptr;
	void *mem;
	uint8_t *mem_byte;
} convert_t;
