#include "term.h"

bool	ft_termcommand(int command) {
	return (ft_termcommand_fd(command, 1));
}
