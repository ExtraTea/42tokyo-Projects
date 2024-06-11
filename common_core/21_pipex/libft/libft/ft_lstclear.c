#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;
	t_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	if (del == NULL)
		return ;
	now = *lst;
	while (now != NULL)
	{
		del(now->content);
		tmp = now->next;
		free(now);
		now = tmp;
	}
	*lst = NULL;
}
