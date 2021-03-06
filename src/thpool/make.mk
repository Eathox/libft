# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    make.mk                                            :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/21 11:10:15 by pholster      #+#    #+#                  #
#    Updated: 2020/05/21 11:10:15 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

libraries += -lpthread

objects += ft_add_tpool_ttask.o
objects += ft_del_tpool.o
objects += ft_del_ttask.o
objects += ft_del_ttask_all.o
objects += ft_get_core_count.o
objects += ft_join_tpool.o
objects += ft_join_ttask.o
objects += ft_join_ttask_all.o
objects += ft_new_tpool.o
objects += ft_new_ttask.o
objects += ft_run_thread.o

objects += ft_add_tqueue_ttask.o
objects += ft_alloc_tpool_tthreads.o
objects += ft_complete_ttask.o
objects += ft_del_tjob.o
objects += ft_del_tqueue.o
objects += ft_del_tthread.o
objects += ft_get_ttask.o
objects += ft_new_tjob.o
objects += ft_new_tqueue.o
objects += ft_new_tthread.o
objects += ft_run_ttask.o
objects += ft_worker_tthread.o
