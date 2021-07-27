#include <signal.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "types/include/types.h"
#include "mem.h"

#define LEN 8

Test(ft_memdel, null) {
	ft_memdel(NULL);
}

Test(ft_memdel, null_content) {
	void *mem;

	mem = NULL;
	ft_memdel(&mem);
	cr_assert_eq(mem, NULL);
}

Test(ft_memdel, memory) {
	void *mem;

	mem = malloc(LEN);
	cr_expect_neq(mem, NULL);

	ft_memdel(&mem);
	cr_assert_eq(mem, NULL);
}

Test(ft_memdel, stack, .signal = SIGABRT) {
	uint8_t mem[LEN];

	cr_redirect_stderr();
	ft_memdel((void**)&mem);
}
