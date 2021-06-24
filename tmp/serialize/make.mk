# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    make.mk                                            :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/21 11:11:13 by pholster      #+#    #+#                  #
#    Updated: 2020/05/21 11:11:13 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

objects += ft_new_serialize.o
objects += ft_new_serialize_read.o
objects += ft_new_serialize_write.o

objects += ft_del_serialize.o

objects += ft_open_serialize.o
objects += ft_close_serialize.o
objects += ft_lseek_serialize.o
objects += ft_write_serialize.o
objects += ft_valid_endian.o
objects += ft_get_endian.o

objects += read_type/ft_read_serialize_int8.o
objects += read_type/ft_read_serialize_int8_ptr.o
objects += read_type/ft_read_serialize_int16.o
objects += read_type/ft_read_serialize_int16_ptr.o
objects += read_type/ft_read_serialize_int32.o
objects += read_type/ft_read_serialize_int32_ptr.o
objects += read_type/ft_read_serialize_int64.o
objects += read_type/ft_read_serialize_int64_ptr.o
objects += read_type/ft_read_serialize_uint8.o
objects += read_type/ft_read_serialize_uint8_ptr.o
objects += read_type/ft_read_serialize_uint16.o
objects += read_type/ft_read_serialize_uint16_ptr.o
objects += read_type/ft_read_serialize_uint32.o
objects += read_type/ft_read_serialize_uint32_ptr.o
objects += read_type/ft_read_serialize_uint64.o
objects += read_type/ft_read_serialize_uint64_ptr.o
objects += read_type/ft_read_serialize_float.o
objects += read_type/ft_read_serialize_float_ptr.o
objects += read_type/ft_read_serialize_double.o
objects += read_type/ft_read_serialize_double_ptr.o
objects += read_type/ft_read_serialize_long_double.o
objects += read_type/ft_read_serialize_long_double_ptr.o
objects += read_type/ft_read_serialize_ptr.o

objects += write_type/ft_write_serialize_int8.o
objects += write_type/ft_write_serialize_int8_ptr.o
objects += write_type/ft_write_serialize_int16.o
objects += write_type/ft_write_serialize_int16_ptr.o
objects += write_type/ft_write_serialize_int32.o
objects += write_type/ft_write_serialize_int32_ptr.o
objects += write_type/ft_write_serialize_int64.o
objects += write_type/ft_write_serialize_int64_ptr.o
objects += write_type/ft_write_serialize_uint8.o
objects += write_type/ft_write_serialize_uint8_ptr.o
objects += write_type/ft_write_serialize_uint16.o
objects += write_type/ft_write_serialize_uint16_ptr.o
objects += write_type/ft_write_serialize_uint32.o
objects += write_type/ft_write_serialize_uint32_ptr.o
objects += write_type/ft_write_serialize_uint64.o
objects += write_type/ft_write_serialize_uint64_ptr.o
objects += write_type/ft_write_serialize_float.o
objects += write_type/ft_write_serialize_float_ptr.o
objects += write_type/ft_write_serialize_double.o
objects += write_type/ft_write_serialize_double_ptr.o
objects += write_type/ft_write_serialize_long_double.o
objects += write_type/ft_write_serialize_long_double_ptr.o
objects += write_type/ft_write_serialize_ptr.o

objects += ft_check_correct_endian.o
objects += ft_correct_endian.o

objects += ft_clear_serialize.o
objects += ft_read_serialize.o

objects += ft_read_serialize_value.o
objects += ft_get_serialize_value.o

objects += ft_write_serialize_value.o
objects += ft_add_serialize_value.o
