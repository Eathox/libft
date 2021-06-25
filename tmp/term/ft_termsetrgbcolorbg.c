#include "term.h"

bool	ft_termsetrgbcolorbg(t_color rgb) {
	return (ft_termsetrgbcolorbg_fd(rgb, 1));
}
