#include "push_swap.h"

void sort_three(t_list *list, t_stack *top, t_stack *middle, t_stack *bottom)
{
	if(top->n < bottom->n && bottom->n < middle->n)
	{
		rotate(list, ra);
		swap(list, sa);
		reverse(list, rra);
	}
	else if(middle->n < top->n && top->n < bottom->n)
		swap(list, sa);
	else if(middle->n < bottom->n && bottom->n < top->n)
	{
		swap(list, sa);
		rotate(list, ra);
		swap(list, sa);
		reverse(list, rra);
	}
	else
	{
		if(middle->n < top->n)
			swap(list, sa);
		rotate(list, ra);
		swap(list, sa);
		reverse(list, rra);
		swap(list, sa);
	}
}

void sort_six(t_list *list, int count)
{
	int pb_count;
	t_stack *st_a;

	pb_count = 0;
	while(list->sorted_num && list->end_a != list->sorted_ena)
		reverse(list, rra);
	if(count > 3)
	{
		if(!(list->start_a->n < list->start_a->next->n && list->start_a->next->n < list->start_a->next->next->n))
			sort_three(list, list->start_a, list->start_a->next, list->start_a->next->next);
		while(pb_count < 3)
		{
			push(list, pb);
			pb_count++;
		}
	}
	if(issorted(list) == ERROR && count - pb_count == 3)
		sort_three(list, list->start_a, list->start_a->next, list->start_a->next->next);
	else if(issorted(list) == ERROR && count - pb_count == 2)
		swap(list, sa);
	st_a = list->start_a;
	while(pb_count)
	{
		if(list->end_a->n > list->start_b->n)
		{
			while(list->start_a->n < list->start_b->n)
				rotate(list, ra);
		}
		push(list, pa);
		while(issorted(list) == ERROR && list->start_b && list->end_a->n > list->start_b->n && list->start_a != st_a)
			reverse(list, rra);
		while(issorted(list) == ERROR && !list->start_b && list->start_a != st_a)
			reverse(list, rra);
		pb_count--;
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
