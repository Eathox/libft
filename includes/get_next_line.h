/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:25:37 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 00:00:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# ifndef BUFF_SIZE
#  define BUFF_SIZE 32
# endif
# define FD content_size
# define STR content

int				get_next_line(const int fd, char **line);
int				get_next_dline(const int fd, char **line, const char *dlm);

#endif
