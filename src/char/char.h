/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 23:46:05 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

# include "ft/types.h"

char		ft_tolower(char c);
char		ft_toupper(char c);
char		ft_getchar(void);
ssize_t		ft_chrdindex(const char *str, const char *dlm);
ssize_t		ft_chrindex(const char *str, char c);
bool		ft_chrdin(const char *str, const char *dlm);
bool		ft_chrin(const char *str, char c);
bool		ft_chrnin(const char *str, char c, size_t n);
void		ft_chrsetbytes(t_uint64 *bytes, const char *src);
bool		ft_chrinbytes(const t_uint64 *bytes, char c);
bool		ft_isalnum(char c);
bool		ft_isalpha(char c);
bool		ft_isascii(char c);
bool		ft_isblank(char c);
bool		ft_isdigit(char c);
bool		ft_ishex(char c);
bool		ft_islower(char c);
bool		ft_isprint(char c);
bool		ft_isspace(char c);
bool		ft_isupper(char c);
bool		ft_putchar(char c);
bool		ft_putchar_fd(char c, int fd);
bool		ft_putnchar(char c, size_t n);
bool		ft_putnchar_fd(char c, size_t n, int fd);

#endif
