#include "term.h"

bool ft_termsetcolorbg(t_uint8 color) {
    return ft_termsetcolorbg_fd(color, 1);
}
