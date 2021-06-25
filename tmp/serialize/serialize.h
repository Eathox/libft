#ifndef SERIALIZE_H
# define SERIALIZE_H

# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

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

typedef struct	s_serialize
{
	int				fd;
	t_endian		endian;
	bool			use_buffer;
	t_endian		target_endian;
	t_uint8			*content;
	size_t			pos;
	size_t			content_size;
	size_t			content_allocated_size;
}				t_serialize;

t_serialize		*ft_new_serialize(t_endian target_endian, bool use_buffer);
t_serialize		*ft_new_serialize_read(int fd, t_endian target_endian,
					bool use_buffer);
t_serialize		*ft_new_serialize_write(int fd, t_endian target_endian,
					bool use_buffer);

void			*ft_del_serialize(t_serialize **serialize);

bool			ft_open_serialize(t_serialize *serialize, char const *file,
					int flags, mode_t mode);
bool			ft_close_serialize(t_serialize **serialize, bool free);
off_t			ft_lseek_serialize(t_serialize *serialize, off_t offset,
					int whence);
ssize_t			ft_write_serialize(t_serialize *serialize);
bool			ft_valid_endian(t_endian endian);
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
					t_int8 const *int8_ptr, size_t size);
ssize_t			ft_write_serialize_int16(t_serialize *serialize, t_int16 int16);
ssize_t			ft_write_serialize_int16_ptr(t_serialize *serialize,
					t_int16 const *int16_ptr, size_t size);
ssize_t			ft_write_serialize_int32(t_serialize *serialize, t_int32 int32);
ssize_t			ft_write_serialize_int32_ptr(t_serialize *serialize,
					t_int32 const *int32_ptr, size_t size);
ssize_t			ft_write_serialize_int64(t_serialize *serialize, t_int64 int64);
ssize_t			ft_write_serialize_int64_ptr(t_serialize *serialize,
					t_int64 const *int64_ptr, size_t size);
ssize_t			ft_write_serialize_uint8(t_serialize *serialize, t_uint8 uint8);
ssize_t			ft_write_serialize_uint8_ptr(t_serialize *serialize,
					t_uint8 const *uint8_ptr, size_t size);
ssize_t			ft_write_serialize_uint16(t_serialize *serialize,
					t_uint16 uint16);
ssize_t			ft_write_serialize_uint16_ptr(t_serialize *serialize,
					t_uint16 const *uint16_ptr, size_t size);
ssize_t			ft_write_serialize_uint32(t_serialize *serialize,
					t_uint32 uint32);
ssize_t			ft_write_serialize_uint32_ptr(t_serialize *serialize,
					t_uint32 const *uint32_ptr, size_t size);
ssize_t			ft_write_serialize_uint64(t_serialize *serialize,
					t_uint64 uint64);
ssize_t			ft_write_serialize_uint64_ptr(t_serialize *serialize,
					t_uint64 const *uint64_ptr, size_t size);
ssize_t			ft_write_serialize_float(t_serialize *serialize, float flt);
ssize_t			ft_write_serialize_float_ptr(t_serialize *serialize,
					float const *flt_ptr, size_t size);
ssize_t			ft_write_serialize_double(t_serialize *serialize, double dbl);
ssize_t			ft_write_serialize_double_ptr(t_serialize *serialize,
					double const *dbl_ptr, size_t size);
ssize_t			ft_write_serialize_long_double(t_serialize *serialize,
					long double ldbl);
ssize_t			ft_write_serialize_long_double_ptr(t_serialize *serialize,
					long double const *ldbl_ptr, size_t size);
ssize_t			ft_write_serialize_ptr(t_serialize *serialize, void const *ptr,
					size_t size);

#endif
