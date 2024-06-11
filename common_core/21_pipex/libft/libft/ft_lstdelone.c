#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
