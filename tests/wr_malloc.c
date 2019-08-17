/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wr_malloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 15:32:59 by pholster       #+#    #+#                */
/*   Updated: 2019/08/17 16:23:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libtest.h"
#include <dlfcn.h>
#include <criterion/criterion.h>

static t_list	*g_malloclst = NULL;
static t_list	*g_malloclstlast = NULL;
static size_t	g_lastmallocsize = 0;
static void		*(*g_real_malloc)(size_t size) = NULL;
static void		(*g_real_free)(void *ptr) = NULL;

void	*wrap_malloc(size_t size)
{
	t_list	lst;
	void	*ptr;

	g_lastmallocsize = size;
	ptr = ft_realmalloc(size);
	lst.next = NULL;
	lst.content = ptr;
	lst.content_size = size;
	if (g_malloclst == NULL)
		g_malloclst = &lst;
	else
		g_malloclstlast->next = &lst;
	g_malloclstlast = &lst;
	return (ptr);
}

void	wrap_free(void *ptr)
{
	t_list *prv;
	t_list *lst;

	prv = NULL;
	lst = g_malloclst;
	if (lst == NULL)
	{
		ft_realfree(NULL);
		return ;
	}
	ft_putpointer(lst);
	ft_putendl("");
	ft_putpointer(&lst->next);
	while (lst != NULL && lst->content != ptr)
	{
		prv = lst;
		lst = lst->next;
	}
	if (lst == NULL)
	{
		ft_realfree(NULL);
		return ;
	}
	if (prv != NULL)
		prv->next = lst->next;
	if (lst == g_malloclstlast)
		g_malloclstlast = prv;
	if (lst == g_malloclst)
		g_malloclst = lst->next;
	ft_realfree(ptr);
}

void	*ft_realmalloc(size_t size)
{
	if (g_real_malloc == NULL)
		g_real_malloc = dlsym(RTLD_NEXT, "malloc");
	return (g_real_malloc(size));
}

void	ft_realfree(void *ptr)
{
	if (g_real_free == NULL)
		g_real_free = dlsym(RTLD_NEXT, "free");
	g_real_free(ptr);
}

void	ft_mallocclearlst(void)
{
	t_list *next;
	t_list *lst;

	lst = g_malloclst;
	while (lst != NULL)
	{
		next = lst->next;
		lst->next = NULL;
		lst = next;
	}
	g_malloclst = NULL;
	g_malloclstlast = NULL;
}

size_t	ft_malloclastsize(void)
{
	return (g_lastmallocsize);
}

size_t	ft_malloclstlen(void)
{
	t_list	*lst;
	size_t	len;

	len = 0;
	lst = g_malloclst;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

t_bool	ft_malloclstempty(void)
{
	return (g_malloclst == NULL && g_malloclstlast == NULL);
}
