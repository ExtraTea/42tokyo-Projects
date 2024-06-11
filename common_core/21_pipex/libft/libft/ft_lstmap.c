#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*now;
	t_list	*newnode;

	if (lst == NULL)
		return (NULL);
	now = NULL;
	while (lst != NULL)
	{
		newnode = ft_lstnew(f(lst->content));
		if (newnode == NULL)
		{
			ft_lstclear(&now, del);
			return (NULL);
		}
		ft_lstadd_back(&now, newnode);
		lst = lst->next;
	}
	return (now);
}
