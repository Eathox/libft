#include "utf8.h"

bool	ft_pututf8str(const t_wchar *str) {
	return (ft_pututf8str_fd(str, 1));
}
