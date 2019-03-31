/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:30 by pholster       #+#    #+#                */
/*   Updated: 2019/03/30 17:28:48 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

/*
** TYPES: (% followed by:)
** d or i = int
** u = unsigned int
** b = unsigned binary (base 2)
** o = unsigned octal (base 8)
** x = unsigned hexadecimal (base 16, lowercase)
** X = unsigned hexadecimal (base 16, uppercase)
** f = double
** a = hexdouble (base 16, lowercase)
** A = hexdouble (base 16, uppercase)
** c = unsigned int (If an l modifier is present, wint_t (wide char))
** s = const char * (If an l modifier is present, const T_WCHAR *)
** p = void *
*/

enum			e_type
{
	INT,
	INT_MAX,
	SHORT,
	LONG,
	DOUBLE,
	SIZE_T,
	CHAR_I,
	CHAR,
	STR,
	VOID,
	T_WCHAR,
	T_WCHAR_STR,
	LONG_LONG,
	LONG_DOUBLE,
	U_INT,
	U_INT_MAX,
	U_SHORT,
	U_LONG,
	U_LONG_LONG,
	U_CHAR_I
};

typedef	struct	s_info
{
	char		flag[7];
	char		prelen;
	char		type;
	int			length;
	int			padprinted;
	int			precision;
	int			printed;
	int			width;
	int			var_len;
	char		var_base;
	enum e_type	var_type;
	void		*var;
	double		var_double;
	long double	var_ldouble;
}				t_info;
typedef long long			t_intmax;
typedef unsigned long long	t_uintmax;

# define PF_VAR_DOUBLE	info->var_double
# define PF_VAR_LDOUBLE	info->var_ldouble
# define PF_GVAR(type)	(type)PF_VAR
# define PF_FLAG		info->flag
# define PF_LENGTH		info->length
# define PF_PRECISION	info->precision
# define PF_PRINTED		info->printed
# define PF_PADPRINTED	info->padprinted
# define PF_TYPE		info->type
# define PF_WIDTH		info->width
# define PF_VAR			info->var
# define PF_VAR_FLOAT	info->f_var
# define PF_VAR_LEN		info->var_len
# define PF_VAR_TYPE	info->var_type
# define PF_VAR_BASE	info->var_base
# define PF_A_TYPE		"fdiuboxXcsp%"
# define PF_A_TYPE_L	"FDOUCS"
# define PF_A_FLAG		"#0-+ \'"
# define PF_A_SPACER	",;:_"
# define PF_A_LENGTH	"hlLjz"
# define PF_A_LENGTH_D	"hl"
# define PF_DOUBLE_H	208
# define PF_DOUBLE_L	216
# define PF_FLAG_HASH	PF_FLAG[0]
# define PF_FLAG_ZERO	PF_FLAG[1]
# define PF_FLAG_MIN	PF_FLAG[2]
# define PF_FLAG_PLUS	PF_FLAG[3]
# define PF_FLAG_SPACE	PF_FLAG[4]
# define PF_FLAG_APOST	PF_FLAG[5]

int				ft_printf(const char *format, ...);
int				pf_commands(const char *str);
int				pf_getflag(t_info *info, const char *str);
int				pf_getinfo(va_list args, t_info *info, const char *str);
int				pf_getlength(t_info *info, const char *str);
int				pf_getprecision(va_list args, t_info *info, const char *str);
int				pf_gettype(t_info *info, const char *str);
int				pf_getwidth(va_list args, t_info *info, const char *str);
int				pf_isnegative(t_info *info);
int				pf_isnegativeint(t_info *info);
int				pf_ispositiveint(t_info *info);
int				pf_issignint(t_info *info);
int				pf_isstr(t_info *info);
int				pf_isunsignint(t_info *info);
int				pf_iszero(t_info *info);
int				pf_iszeropad(t_info *info);
int				pf_putstr(t_info *info, char *str);
int				pf_setcolor(const char *start);
t_info			*pf_infonew(void);
t_intmax		pf_overflowsigned(t_info *info);
t_uintmax		pf_overflowunsigned(t_info *info);
void			pf_getdoublelen(t_info *info);
void			pf_getsignedlen(t_info *info);
void			pf_getstrlen(t_info *info);
void			pf_getunsignedlen(t_info *info);
void			pf_getutf8strlen(t_info *info);
void			pf_infosetdefualt(t_info *info);
void			pf_print(t_info *info);
void			pf_printbackpad(t_info *info);
void			pf_printchar(t_info *info);
void			pf_printdouble(t_info *info);
void			pf_printpad(t_info *info);
void			pf_printstr(t_info *info);
void			pf_putchar(t_info *info, char c);
void			pf_putinfo(t_info *info);
void			pf_putnstr(t_info *info, char *str, size_t n);
void			pf_putnum(t_info *info);
void			pf_putnutf8str(t_info *info, t_wchar *str, size_t n);
void			pf_putunum(t_info *info);
void			pf_putwchar(t_info *info, t_wchar c);
void			pf_setvar_base(t_info *info);
void			pf_setvar_len(t_info *info);
void			pf_setvar_type(t_info *info);

#endif
