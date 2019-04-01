/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_printpad.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:15:04 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	putn(t_info *info, char *str, size_t n)
{
	pf_putnstr(info, str, n);
	if (PF_VAR_TYPE == VOID && PF_WIDTH <= PF_PRECISION)
		return (0);
	if (PF_PRECISION > PF_WIDTH && ft_strequ(str, "0") == FALSE)
		return (0);
	return ((int)n);
}

static void	putspace(t_info *info, int space)
{
	while (space > 0 && PF_FLAG_MIN == FALSE)
	{
		pf_putchar(info, ' ');
		space--;
	}
}

static void	putzero(t_info *info, int len, int space, char *prfx)
{
	int		prelen;
	char	c;

	prelen = ft_strlen(prfx);
	c = (pf_iszeropad(info)) ? '0' : ' ';
	len = len - ft_max(0, space);
	if (PF_VAR_TYPE == VOID || pf_iszero(info) == FALSE)
		len -= putn(info, prfx, prelen);
	else if (ft_tolower(prfx[1]) != 'x' && PF_TYPE != 'o')
		len -= putn(info, prfx, prelen);
	while (len > 0 && (PF_FLAG_MIN == FALSE || c != ' '))
	{
		pf_putchar(info, c);
		len--;
	}
}

static char	*getprefix(t_info *info, char *prfx)
{
	if (pf_isnegative(info))
		prfx = "-";
	else if (PF_FLAG_PLUS && pf_ispositiveint(info))
		prfx = "+";
	else if (PF_FLAG_SPACE && pf_ispositiveint(info))
		prfx = " ";
	else if ((PF_FLAG_HASH && ft_chrin("xX", PF_TYPE)) || PF_VAR_TYPE == VOID)
		prfx = (PF_TYPE == 'X') ? "0X" : "0x";
	else if (PF_FLAG_HASH && PF_TYPE == 'o' &&
		pf_iszero(info) == FALSE && PF_PRECISION <= PF_VAR_LEN)
		prfx = "0";
	return (prfx);
}

void		pf_printpad(t_info *info)
{
	char	*prfx;
	int		prelen;
	int		prtinted;
	int		len;
	int		space;

	prfx = "";
	prtinted = PF_PRINTED;
	prfx = getprefix(info, prfx);
	prelen = ft_strlen(prfx);
	if (PF_PRECISION > PF_WIDTH && pf_isstr(info) == FALSE)
		len = ft_max(0, PF_PRECISION) - PF_VAR_LEN;
	else
		len = ft_max(0, PF_WIDTH) - PF_VAR_LEN;
	space = ft_max(0, PF_WIDTH) - ft_max(PF_VAR_LEN, PF_PRECISION);
	if (PF_VAR_TYPE == VOID || pf_iszero(info) == FALSE)
		space -= prelen;
	else if (ft_tolower(prfx[1]) != 'x' && PF_TYPE != 'o')
		space -= prelen;
	if (PF_FLAG_ZERO &&
		(PF_PRECISION == -1 || (PF_PRECISION == 0 && PF_FLAG_HASH == FALSE)))
		space = 0;
	putspace(info, space);
	putzero(info, len, space, prfx);
	PF_PADPRINTED = PF_PRINTED - prtinted;
}
