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

# include <stdlib.h>
# include <stdbool.h>

bool		ft_isalnum(
	char c
);

bool		ft_isalpha(
	char c
);

bool		ft_isascii(
	char c
);

bool		ft_isbinary(
	char c
);

bool		ft_isblank(
	char c
);

bool		ft_iscntrl(
	char c
);

bool		ft_isdigit(
	char c
);

bool		ft_isgraph(
	char c
);

bool		ft_ishex(
	char c
);

bool		ft_islower(
	char c
);

bool		ft_isoctal(
	char c
);

bool		ft_isprint(
	char c
);

bool		ft_isspace(
	char c
);

bool		ft_isupper(
	char c
);

char		ft_tolower(
	char c
);

char		ft_toupper(
	char c
);

#endif
