/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   serialize.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 11:10:53 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/20 18:30:27 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_H
# define SERIALIZE_H

# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "ft/bool.h"
# include "ft/types.h"

# ifndef SERIALIZE_BUFF_SIZE
#  define SERIALIZE_BUFF_SIZE 42
# endif

/*
** TODO: Seprate content to seprate struct, and keep content_pos local
*/

typedef enum	e_endian
{
	ENDIAN_INVALID = -1,
	ENDIAN_BIG,
	ENDIAN_LITTLE,
	ENDIAN_COUNT,
}				t_endian;

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

typedef struct	s_serialize
{
	int				fd;
	t_endian		endian;
	t_bool			use_buffer;
	t_endian		target_endian;
	t_uint8			*content;
	size_t			content_pos;
	size_t			content_size;
	size_t			content_allocated_size;
}				t_serialize;

t_serialize		*ft_new_serialize(t_endian target_endian, t_bool use_buffer);
t_serialize		*ft_new_serialize_read(int fd, t_endian target_endian,
					t_bool use_buffer);
t_serialize		*ft_new_serialize_write(int fd, t_endian target_endian,
					t_bool use_buffer);

void			*ft_del_serialize(t_serialize **serialize);

t_bool			ft_open_serialize(t_serialize *serialize, char const *file,
					int flags, mode_t mode);
t_bool			ft_close_serialize(t_serialize *serialize);
off_t			ft_lseek_serialize(t_serialize *serialize, off_t offset,
					int whence);
void			ft_clear_serialize(t_serialize *serialize);
ssize_t			ft_read_serialize(t_serialize *serialize);
ssize_t			ft_write_serialize(t_serialize *serialize, t_bool clear);
t_bool			ft_valid_endian(t_endian endian);
t_endian		ft_get_endian(void);

ssize_t			ft_read_serialize_int8(t_serialize *serialize, t_int8 *int8);
ssize_t			ft_read_serialize_int8_ptr(t_serialize *serialize,
					t_int8 **int8_ptr, size_t size);
ssize_t			ft_read_serialize_int16(t_serialize *serialize, t_int16 *int16);
ssize_t			ft_read_serialize_int16_ptr(t_serialize *serialize,
					t_int16 **int16_ptr, size_t size);
ssize_t			ft_read_serialize_int32(t_serialize *serialize, t_int32 *int32);
ssize_t			ft_read_serialize_int32_ptr(t_serialize *serialize,
					t_int32 **int32_ptr, size_t size);
ssize_t			ft_read_serialize_int64(t_serialize *serialize, t_int64 *int64);
ssize_t			ft_read_serialize_int64_ptr(t_serialize *serialize,
					t_int64 **int64_ptr, size_t size);
ssize_t			ft_read_serialize_uint8(t_serialize *serialize, t_uint8 *uint8);
ssize_t			ft_read_serialize_uint8_ptr(t_serialize *serialize,
					t_uint8 **uint8_ptr, size_t size);
ssize_t			ft_read_serialize_uint16(t_serialize *serialize,
					t_uint16 *uint16);
ssize_t			ft_read_serialize_uint16_ptr(t_serialize *serialize,
					t_uint16 **uint16_ptr, size_t size);
ssize_t			ft_read_serialize_uint32(t_serialize *serialize,
					t_uint32 *uint32);
ssize_t			ft_read_serialize_uint32_ptr(t_serialize *serialize,
					t_uint32 **uint32_ptr, size_t size);
ssize_t			ft_read_serialize_uint64(t_serialize *serialize,
					t_uint64 *uint64);
ssize_t			ft_read_serialize_uint64_ptr(t_serialize *serialize,
					t_uint64 **uint64_ptr, size_t size);
ssize_t			ft_read_serialize_float(t_serialize *serialize, float *flt);
ssize_t			ft_read_serialize_float_ptr(t_serialize *serialize,
					float **flt_ptr, size_t size);
ssize_t			ft_read_serialize_double(t_serialize *serialize, double *dbl);
ssize_t			ft_read_serialize_double_ptr(t_serialize *serialize,
					double **dbl_ptr, size_t size);
ssize_t			ft_read_serialize_long_double(t_serialize *serialize,
					long double *ldbl);
ssize_t			ft_read_serialize_long_double_ptr(t_serialize *serialize,
					long double **ldbl_ptr, size_t size);
ssize_t			ft_read_serialize_ptr(t_serialize *serialize, void **ptr,
					size_t size);

ssize_t			ft_write_serialize_int8(t_serialize *serialize, t_int8 int8);
ssize_t			ft_write_serialize_int8_ptr(t_serialize *serialize,
					t_int8 *int8_ptr, size_t size);
ssize_t			ft_write_serialize_int16(t_serialize *serialize, t_int16 int16);
ssize_t			ft_write_serialize_int16_ptr(t_serialize *serialize,
					t_int16 *int16_ptr, size_t size);
ssize_t			ft_write_serialize_int32(t_serialize *serialize, t_int32 int32);
ssize_t			ft_write_serialize_int32_ptr(t_serialize *serialize,
					t_int32 *int32_ptr, size_t size);
ssize_t			ft_write_serialize_int64(t_serialize *serialize, t_int64 int64);
ssize_t			ft_write_serialize_int64_ptr(t_serialize *serialize,
					t_int64 *int64_ptr, size_t size);
ssize_t			ft_write_serialize_uint8(t_serialize *serialize, t_uint8 uint8);
ssize_t			ft_write_serialize_uint8_ptr(t_serialize *serialize,
					t_uint8 *uint8_ptr, size_t size);
ssize_t			ft_write_serialize_uint16(t_serialize *serialize,
					t_uint16 uint16);
ssize_t			ft_write_serialize_uint16_ptr(t_serialize *serialize,
					t_uint16 *uint16_ptr, size_t size);
ssize_t			ft_write_serialize_uint32(t_serialize *serialize,
					t_uint32 uint32);
ssize_t			ft_write_serialize_uint32_ptr(t_serialize *serialize,
					t_uint32 *uint32_ptr, size_t size);
ssize_t			ft_write_serialize_uint64(t_serialize *serialize,
					t_uint64 uint64);
ssize_t			ft_write_serialize_uint64_ptr(t_serialize *serialize,
					t_uint64 *uint64_ptr, size_t size);
ssize_t			ft_write_serialize_float(t_serialize *serialize, float flt);
ssize_t			ft_write_serialize_float_ptr(t_serialize *serialize,
					float *flt_ptr, size_t size);
ssize_t			ft_write_serialize_double(t_serialize *serialize, double dbl);
ssize_t			ft_write_serialize_double_ptr(t_serialize *serialize,
					double *dbl_ptr, size_t size);
ssize_t			ft_write_serialize_long_double(t_serialize *serialize,
					long double ldbl);
ssize_t			ft_write_serialize_long_double_ptr(t_serialize *serialize,
					long double *ldbl_ptr, size_t size);
ssize_t			ft_write_serialize_ptr(t_serialize *serialize, void *ptr,
					size_t size);

#endif
