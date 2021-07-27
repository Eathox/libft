#include <limits.h>
#include <string.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "types/include/types.h"
#include "mem.h"

#define STEP 0x1
#define MAX CHAR_MAX

#define ALIGN_SIZE 512

#define SINGLE_SIZE (sizeof(uint8_t) * 1)

typedef struct param_s
{
	uint32_t mem;
	uint32_t needle;
	size_t needle_pos;
	bool insert_needle;
} params_t;

ParameterizedTestParameters(ft_memmem, general) {
	static params_t params[] = {
		{0x0, 0x0, 0, false},
		{0xFFFFFFFF, 0xFFFFFFFF, 0, false},
		{0xFF00FF00, 0x00FF00FF, 1, false},
		{0xFF0000FF, 0x0000FFFF, 3, false},
		{0xFF0000FF, 0xFF00FF00, 246, true},
		{0xFFFFFFFF, 0xF0F0F0F0, ALIGN_SIZE - sizeof(uint32_t), true},
	};

	size_t const count = sizeof(params) / sizeof(*params);
	return cr_make_param_array(params_t, params, count);
}

ParameterizedTest(params_t *param, ft_memmem, general) {
	size_t const size = ALIGN_SIZE;
	size_t const needle_len = sizeof(param->needle);
	uint8_t *mem_byte = calloc(size, sizeof(*mem_byte));
	uint8_t *needle_byte = calloc(needle_len, sizeof(*needle_byte));
	uint8_t *result;

	cr_expect_neq(mem_byte, NULL);
	cr_expect_neq(needle_byte, NULL);

	ft_memset4(mem_byte, param->mem, size / sizeof(uint32_t));
	ft_memset4(needle_byte, param->needle, needle_len / sizeof(uint32_t));
	if (param->insert_needle == true)
		memcpy(mem_byte + param->needle_pos, needle_byte, needle_len);

	result = ft_memmem(mem_byte, size, needle_byte, needle_len);
	cr_assert_eq(param->needle_pos, (size_t)(result - mem_byte), "%08X %08X %zu",
		param->mem, param->needle, param->needle_pos);

	free(mem_byte);
}

Test(ft_memmem, not_found) {
	size_t const len = SINGLE_SIZE;
	uint8_t mem_byte[SINGLE_SIZE];
	uint8_t needle_byte[SINGLE_SIZE];
	uint8_t *result;

	bzero(mem_byte, len);
	memset(needle_byte, UCHAR_MAX, len);

	result = ft_memmem(mem_byte, len, needle_byte, len);
	cr_assert_eq(result, NULL);
}

Test(ft_memmem, needle_to_long) {
	size_t const len = SINGLE_SIZE;
	uint8_t mem_byte[SINGLE_SIZE];
	uint8_t *result;

	bzero(mem_byte, len);

	result = ft_memmem(mem_byte, len, mem_byte, len * 2);
	cr_assert_eq(result, NULL);
}

Test(ft_memmem, zero_length) {
	size_t const len = SINGLE_SIZE;
	uint8_t mem_byte[SINGLE_SIZE];
	uint8_t *result;

	result = ft_memmem(mem_byte, len, NULL, 0);
	cr_assert_eq(result, mem_byte);
}
