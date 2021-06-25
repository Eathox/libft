#include "str.h"

ssize_t		ft_getnextline(int fd, char **line) {
	return (ft_getnextdline(fd, line, '\n'));
}
