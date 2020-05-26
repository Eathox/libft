# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    make.mk                                            :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/21 11:14:43 by pholster      #+#    #+#                  #
#    Updated: 2020/05/21 11:14:43 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

objects += ft_calloc.o
objects += ft_memalloc.o

objects += ft_arraydel.o
objects += ft_memdel.o

objects += ft_bzero.o
objects += ft_memset.o
objects += ft_memset4.o
objects += ft_memrev.o

objects += ft_memchr.o
objects += ft_memcmp.o

tests += ft_calloc_test.o
tests += ft_memalloc_test.o

tests += ft_arraydel_test.o
tests += ft_memdel_test.o

tests += ft_bzero_test.o
tests += ft_memset_test.o
tests += ft_memset4_test.o
tests += ft_memrev_test.o

tests += ft_memchr_test.o
tests += ft_memcmp_test.o
