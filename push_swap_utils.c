#include "push_swap.h"

void sort_small_stack_bottom(t_list *list, int ra_count);
void three_small_sort(t_list *list, int count);
void three_mid_sort(t_list *list, int count);

void sort_small_stack_bottom(t_list *list, int count)
{
	if(count == 1)
		ash(list, rra);
	else if(count == 2)
	{
		ash(list, rra);
		ash(list, rra);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
	}
	else
	{
		ash(list, rra);
		if(list->end_a->prev->n > list->end_a->n && list->end_a->prev->n > list->start_a->n)
		{
			ash(list, pb);
			ash(list, rra);
			ash(list, rra);
			ash(list, sa);
			ash(list, pa);
		}
		else
		{
			ash(list, rra);
			if(list->start_a->n > list->start_a->next->n)
				ash(list, sa);
			ash(list, rra);
		}
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
	}
}

void three_mid_sort(t_list *list, int count)
{
	if(count == 1)
		ash(list, pa);
	else if(count == 2)
	{
		ash(list, pa);
		ash(list, pa);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
	}
	else
	{
		if(list->start_b->n < list->start_b->next->n)
			ash(list, sb);
		ash(list, pa);
		if(list->start_b->n < list->start_b->next->n)
			ash(list, sb);
		ash(list, pa);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		ash(list, pa);
	}
}

void three_small_sort(t_list *list, int count)
{
	if(count == 1)
	{
		ash(list, rrb);
		ash(list, pa);
	}
	else if(count == 2)
	{
		ash(list, rrb);
		ash(list, rrb);
		ash(list, pa);
		ash(list, pa);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
	}
	else
	{
		ash(list, rrb);
		ash(list, rrb);
		ash(list, rrb);
		three_mid_sort(list, 3);
	}
}
