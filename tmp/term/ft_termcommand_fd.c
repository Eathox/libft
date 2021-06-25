#include "ft/char.h"
#include "ft/str.h"
#include "ft/num.h"

#include "term.h"

bool	ft_termcommand_fd(int command, int fd) {
	if (ft_putstr_fd("\033[", fd) == false)
		return (false);
	if (ft_putnum_fd(command, fd) == false)
		return (false);
	return (ft_putchar_fd('m', fd));
}
