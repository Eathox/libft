#include "../include/char.h"

bool ft_isalpha(
    char c
) {
    return (ft_islower(c) || ft_isupper(c));
}
