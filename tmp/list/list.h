#ifndef FT_LIST_H
# define FT_LIST_H

# include <string.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstdup(const t_list *lst);
t_list			*ft_lstdupone(const t_list *lst);
t_list			*ft_lstfind_content(t_list *lst, const void *content,
					size_t size);
t_list			*ft_lstfind_size(t_list *lst, size_t size);
t_list			*ft_lstfindadd_content(t_list *lst, const void *content,
					size_t size);
t_list			*ft_lstfindadd_size(t_list *lst, size_t size);
t_list			*ft_lstindex(t_list *lst, size_t index);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(const t_list *lst, t_list *(*f)(const t_list *elem));
t_list			*ft_lstnew(void *content, size_t content_size);
t_list			*ft_lstnew_dup(const void *content, size_t content_size);
t_list			*ft_lstunlink(t_list **head, t_list *lst);
size_t			ft_lstlen(const t_list *lst);
size_t			ft_lstnlen(const t_list *lst, size_t n);
void			ft_lstadd(t_list **head, t_list *new);
void			ft_lstaddbck(t_list **head, t_list *new);
void			ft_lstdel(t_list **head, void (*del)(void *, size_t));
void			ft_lstdelmem(void *content, size_t size);
void			ft_lstdelone(t_list **head, void (*del)(void *, size_t));
void			ft_lstinsert(t_list *head, t_list *lst);
void			ft_lstiter(const t_list *lst, void (*f)(const t_list *elem));
void			ft_lstrev(t_list **head);
char			**ft_lsttostrarr(t_list *lst);
intmax_t		*ft_lsttonumarr(t_list *lst);
bool			ft_lstsortstrac(const t_list *sortlst, const t_list *lst);
void			ft_lstsort(t_list **head,
					bool (*f)(const t_list *, const t_list *));
void			ft_lstsortrev(t_list **head,
					bool (*f)(const t_list *, const t_list *));
bool			ft_putlstsize(const t_list *lst);
bool			ft_putnumlst(const t_list *lst);
bool			ft_putstrlst(const t_list *lst);

#endif
