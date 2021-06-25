#include "term.h"

bool	ft_termsetcolor(t_uint8 color) {
	return (ft_termsetcolor_fd(color, 1));
}
