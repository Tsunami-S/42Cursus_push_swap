#include "push_swap.h"

int	issorted_a(t_list *list)
{
	t_stack	*now;

	if (!list)
		return (ERROR);
	now = list->start_a;
	while (now != list->end_a)
	{
		if (now->n > now->next->n)
			return (ERROR);
		now = now->next;
	}
	return (SUCCESS);
}

int issorted_go_next(t_stack *start, int count)
{
	t_stack *now;
	int i;

	i = 0;
	now = start;
	if(start->n < start->next->n)
	{
		while(i < count - 1)
		{
			if(now->n > now->next->n)
				return ERROR;
			now = now->next;
			i++;
		}
		return PLUS;
	}
	while(i < count - 1)
	{
		if(now->n < now->next->n)
			return ERROR;
		now = now->next;
		i++;
	}
	return MINUS;
}

int issorted_go_prev(t_stack *start, int count)
{
	int i;
	t_stack *now;

	i = 0;
	now = start;
	if(start->n < start->prev->n)
	{
		while(i < count - 1)
		{
			if(now->n > now->prev->n)
				return ERROR;
			now = now->prev;
			i++;
		}
		return PLUS;
	}
	while(i < count - 1)
	{
		if(now->n < now->prev->n)
			return ERROR;
		now = now->prev;
		i++;
	}
	return MINUS;
}
