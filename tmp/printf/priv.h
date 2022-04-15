#ifndef FT_PRIV_H
#define FT_PRIV_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "ft/color.h"
#include "ft/list.h"
#include "ft/types.h"
#include "ft/utf8.h"

/*
** * * TYPES: (% followed by:)
** * d or i = int
** * u = unsigned int
** * b = unsigned binary (base 2)
** * o = unsigned octal (base 8)
** * x = unsigned hexadecimal (base 16, lowercase)
** * X = unsigned hexadecimal (base 16, uppercase)
** * f = double
** * a = hexdouble (base 16, lowercase)
** * A = hexdouble (base 16, uppercase)
** * c = unsigned int (If an l modifier is present, wint_t (wide char))
** * s = char * (If an l modifier is present, T_WCHAR *)
** * p = void *
*/

#define PF_A_TYPE "fdiuboxXcsp%"
#define PF_A_TYPE_L "FDOUCS"
#define PF_A_FLAG "#0-+ \'"
#define PF_A_SPACER ",;:_"
#define PF_A_LENGTH "hlLjz"
#define PF_A_LENGTH_D "hl"
#define PF_DOUBLE_H 208
#define PF_DOUBLE_L 216
#define PF_FLAG_HASH info->flag[0]
#define PF_FLAG_ZERO info->flag[1]
#define PF_FLAG_MIN info->flag[2]
#define PF_FLAG_PLUS info->flag[3]
#define PF_FLAG_SPACE info->flag[4]
#define PF_FLAG_APOST info->flag[5]
#define PF_BUFF_SIZE 256

typedef enum e_type {
    INT,
    MAX_INT,
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
    MAX_U_INT,
    U_SHORT,
    U_LONG,
    U_LONG_LONG,
    U_CHAR_I
} t_type;

typedef struct s_info {
    va_list args;
    bool flag[7];
    char type;
    char width;
    int length;
    ssize_t precision;
    ssize_t var_len;
    t_type var_type;
    int var_base;
    bool is_zero;
    bool is_negative;
    char *buff;
    t_list *buff_list;
    size_t buff_len;
    size_t added;
    size_t padadded;
    int fd;
} t_info;

/*
** ----------------------------Distribute Functions-----------------------------
*/

size_t ft_commands(t_info *info, const char *str);
size_t ft_distribute(t_info *info, const char *start);
void ft_formatdistribute(t_info *info);

/*
** -------------------------------Info Functions--------------------------------
*/

t_info *ft_infonew(void);
void ft_infosetdefault(t_info *info);
size_t ft_getinfo(t_info *info, const char *str);
size_t ft_getflag(t_info *info, const char *str);
size_t ft_getprecision(t_info *info, const char *str);
size_t ft_getwidth(t_info *info, const char *str);
int ft_getlength(t_info *info, const char *str);
int ft_gettype(t_info *info, const char *str);
void ft_setvar_base(t_info *info);
void ft_setvar_type(t_info *info);

/*
** ------------------------------Format Functions-------------------------------
*/

void ft_formatbackpad(t_info *info);
void ft_formatchar(t_info *info);
void ft_formatdouble(t_info *info);
void ft_formatnum(t_info *info);
void ft_formatpad(t_info *info);
void ft_formatstr(t_info *info);
void ft_formatunum(t_info *info);
size_t ft_formatcolor(t_info *info, const char *start);

/*
** -------------------------Buffer Management Functions-------------------------
*/

bool ft_addtobuff(t_info *info, const char *str, size_t len);
size_t ft_addstr(t_info *info, const char *str);
void ft_addchar(t_info *info, char c);
void ft_addnstr(t_info *info, const char *str, size_t n);
void ft_addnum(t_info *info, intmax_t value);
void ft_addunum(t_info *info, uintmax_t value, size_t len, int base);
void ft_addwchar(t_info *info, t_wchar c);
void ft_addwcharstr(t_info *info, const t_wchar *str, size_t n);
void ft_addcolor(t_info *info, int color);
void ft_addcolorbg(t_info *info, int color);
void ft_addrgbcolor(t_info *info, t_uint8 r, t_uint8 g, t_uint8 b);
void ft_addrgbcolorbg(t_info *info, t_uint8 r, t_uint8 g, t_uint8 b);

/*
** --------------------------------Is Functions---------------------------------
*/

bool ft_ispositiveint(const t_info *info);
bool ft_issignint(const t_info *info);
bool ft_isstr(const t_info *info);
bool ft_isunsignint(const t_info *info);
bool ft_iszeropad(const t_info *info);

/*
** -----------------------------Overflow Functions------------------------------
*/

intmax_t ft_overflowsigned(t_info *info);
uintmax_t ft_overflowunsigned(t_info *info);

#endif
