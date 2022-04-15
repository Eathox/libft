#ifndef FT_NUMARR_H
#define FT_NUMARR_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "ft/list.h"

bool ft_putnumarr(const intmax_t *arr, size_t len);
t_list *ft_numarrtolst(const intmax_t *arr, size_t len);
bool ft_numarrsortac(intmax_t current, intmax_t num);
void ft_numarrsort(intmax_t *arr, bool (*f)(intmax_t, intmax_t), size_t len);
void ft_numarrsortrev(intmax_t *arr, bool (*f)(intmax_t, intmax_t), size_t len);

#endif
