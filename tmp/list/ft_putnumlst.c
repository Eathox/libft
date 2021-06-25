#include "ft/str.h"
#include "ft/num.h"
#include "ft/char.h"

#include "list.h"

static bool	put_content(void *content, size_t size) {
	if (size == sizeof(char))
		return (ft_putnum(*((char *)content)));
	else if (size == sizeof(short))
		return (ft_putnum(*((short *)content)));
	else if (size == sizeof(int))
		return (ft_putnum(*((int *)content)));
	else if (size == sizeof(long))
		return (ft_putnum(*((long *)content)));
	else
		return (ft_putnum(*((intmax_t *)content)));
	return (false);
}

bool			ft_putnumlst(const t_list *lst) {
	if (lst == NULL)
		return (ft_putstr(NULL));
	if (put_content(lst->content, lst->content_size) == false)
		return (false);
	if (ft_putchar('\n') == false)
		return (false);
	if (lst->next != NULL)
		return (ft_putnumlst(lst->next));
	return (true);
}
