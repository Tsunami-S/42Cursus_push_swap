#include "push_swap.h"

void delete_list(t_list *start)
{
	t_list *tmp;

	while(start)
	{
		tmp = start;
		start = start->next;
		free(tmp);
	}
}
