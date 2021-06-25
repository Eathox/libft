#include "ft/str.h"
#include "ft/mem.h"

#include "strarr.h"

static t_list	*freeret(t_list **lst) {
	ft_lstdel(lst, &ft_lstdelmem);
	return (NULL);
}

t_list			*ft_strarrtolst(const char **arr) {
	size_t	i;
	t_list	*newlst;
	t_list	*prvlst;
	t_list	*returnlst;

	i = 0;
	returnlst = ft_lstnew_dup(arr[i], ft_strlen(arr[i]) + 1);
	if (returnlst == NULL)
		return (NULL);
	prvlst = returnlst;
	i++;
	while (arr[i] != NULL)
	{
		newlst = ft_lstnew_dup(arr[i], ft_strlen(arr[i]) + 1);
		if (newlst == NULL)
			return (freeret(&returnlst));
		prvlst->next = newlst;
		prvlst = newlst;
		i++;
	}
	return (returnlst);
}
