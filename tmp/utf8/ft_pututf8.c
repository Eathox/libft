#include "utf8.h"

bool	ft_pututf8(t_wchar c) {
	return (ft_pututf8_fd(c, 1));
}
