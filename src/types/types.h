/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/21 19:32:21 by pholster      #+#    #+#                 */
/*   Updated: 2019/09/21 19:32:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

typedef	char				t_int8;
typedef	short				t_int16;
typedef int					t_int32;
typedef	long int			t_int64;
typedef	unsigned char		t_uint8;
typedef	unsigned short		t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long int	t_uint64;

/*
** * Union used to read any type 1 byte at an time using the 'stream' field
** * Or treat data as if it was a different type with out type-casting
*/
typedef union	u_convert
{
	t_int8			int8;
	t_int8			*int8_ptr;
	t_int16			int16;
	t_int16			*int16_ptr;
	t_int32			int32;
	t_int32			*int32_ptr;
	t_int64			int64;
	t_int64			*int64_ptr;
	t_uint8			uint8;
	t_uint8			*uint8_ptr;
	t_uint16		uint16;
	t_uint16		*uint16_ptr;
	t_uint32		uint32;
	t_uint32		*uint32_ptr;
	t_uint64		uint64;
	t_uint64		*uint64_ptr;
	float			flt;
	float			*flt_ptr;
	double			dbl;
	double			*dbl_ptr;
	long double		ldbl;
	long double		*ldbl_ptr;
	void			*ptr;
	t_uint8			*stream;
}				t_convert;

#endif
