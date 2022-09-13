#include "../minishell.h"

t_pid	*ft_lstnew_pid(int id)
{
	t_pid	*p;

	p = (t_pid *) malloc(sizeof(t_pid));
	if (!p)
		return (0);
	p->pid = id;
	p->next = NULL;
	return (p);
}

t_pid	*ft_lstlast_pid(t_pid *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back_pid(t_pid **lst, t_pid *new)
{
	t_pid	*tmp;

	if (*lst)
	{
		tmp = ft_lstlast_pid((*lst));
		tmp -> next = new;
	}
	else
		*lst = new;
}