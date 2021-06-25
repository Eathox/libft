#include "term.h"

bool	ft_termsetrgbcolor(t_color rgb) {
	return (ft_termsetrgbcolor_fd(rgb, 1));
}
