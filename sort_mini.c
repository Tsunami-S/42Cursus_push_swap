#include "push_swap.h"

void sort_six(t_list *list, int count)
{
	while(list->sorted_num && list->end_a != list->sorted_ena)
		ash(list, rra);
	if(issorted(list) == ERROR && count == 2)
		ash(list, sa);
	else if(issorted(list) == ERROR && count == 3)
	{
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		ash(list, pb);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		ash(list, pa);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
	}
	else if(issorted(list) == ERROR && count == 4)
	{
		t_stack *tmp = list->start_b;
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		ash(list, ra);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		ash(list, pb);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		if(list->start_b->n > list->end_a->n)
			ash(list, pa);
		else
			ash(list, rra);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		if(list->start_b != tmp)
			ash(list, pa);
		else
			ash(list, rra);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
	}
	list->sorted_sta = list->start_a;
	list->sorted_ena = list->end_a;
	list->sorted_num = stack_count(list->start_a);
}

int stack_count(t_stack *stack)
{
	int count;

	count = 0;
	while(stack)
	{
		stack = stack->next;
		count++;
	}
	return count;
}

int	issorted(t_list *list)
{
	t_stack	*now;

	now = list->start_a;
	if (!now)
		return (ERROR);
	while (now->next)
	{
		if (now->n > now->next->n)
			return (ERROR);
		now = now->next;
	}
	list->sorted_sta = list->start_a;
	list->sorted_ena = list->end_a;
	list->sorted_num = stack_count(list->start_a);
	return (SUCCESS);
}

void search_max_and_min(t_stack *start, int *max, int *min)
{
	*min = 0;
	*max = 0;
	while(start)
	{
		if(start->n < *min)
			*min = start->n;
		else if(start->n > *max)
			*max = start->n;
		start = start->next;
	}
}
