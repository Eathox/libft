/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmem_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 19:37:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/18 19:37:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <string.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "ft/types.h"
#include "mem.h"

#define STEP 0x19
#define MAX (STEP * 20)

#define SINGLE_SIZE (sizeof(t_uint8) * 1)

typedef struct	s_param
{
	t_uint32	mem;
	t_uint32	needle;
	size_t		needle_pos;
	bool		insert_needle;
}				t_param;

ParameterizedTestParameters(ft_memmem, general)
{
	static t_param 	params[] = {
		{0x0, 0x0, 0, false},
		{0xFFFFFFFF, 0xFFFFFFFF, 0, false},
		{0xFF0000FF, 0x0000FFFF, 3, false},
		{0xFF00FF00, 0x00FF00FF, 1, false},
		{0xFF0000FF, 0xFF00FF00, 246, true},
		{0xFFFFFFFF, 0xF0F0F0F0, MAX - sizeof(t_uint32), true},
	};

	size_t const	count = sizeof(params) / sizeof(*params);
	return cr_make_param_array(t_param, params, count);
}

ParameterizedTest(t_param *param, ft_memmem, general)
{
	size_t const	size = MAX;
	size_t const	needle_len = sizeof(param->needle);
	t_uint8			*mem_byte = calloc(size, sizeof(*mem_byte));
	t_uint8			*needle_byte = calloc(needle_len, sizeof(*needle_byte));
	t_uint8			*result;

	cr_expect_neq(mem_byte, NULL);
	cr_expect_neq(needle_byte, NULL);

	ft_memset4(mem_byte, param->mem, size / sizeof(t_uint32));
	ft_memset4(needle_byte, param->needle, needle_len / sizeof(t_uint32));
	if (param->insert_needle == true)
		memcpy(mem_byte + param->needle_pos, needle_byte, needle_len);

	result = ft_memmem(mem_byte, size, needle_byte, needle_len);
	cr_assert_eq(param->needle_pos, result - mem_byte, "%08X %08X %zu",
		param->mem, param->needle, param->needle_pos);

	free(mem_byte);
}

Test(ft_memmem, not_found)
{
	size_t const	len = SINGLE_SIZE;
	t_uint8 		mem_byte[len];
	t_uint8 		needle_byte[len];
	t_uint8			*result;

	bzero(mem_byte, len);
	memset(needle_byte, UCHAR_MAX, len);

	result = ft_memmem(mem_byte, len, needle_byte, len);
	cr_assert_eq(result, NULL);
}

Test(ft_memmem, needle_to_long)
{
	size_t const	len = SINGLE_SIZE;
	t_uint8 		mem_byte[len];
	t_uint8			*result;

	bzero(mem_byte, len);

	result = ft_memmem(mem_byte, len, mem_byte, len * 2);
	cr_assert_eq(result, NULL);
}

Test(ft_memmem, zero_length)
{
	size_t const	len = SINGLE_SIZE;
	t_uint8 		mem_byte[len];
	t_uint8			*result;

	result = ft_memmem(mem_byte, len, NULL, 0);
	cr_assert_eq(result, mem_byte);
}
