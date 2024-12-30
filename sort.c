#include "push_swap.h"

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

void sort_three(t_list *list, int count)
{
	t_stack *top;
	t_stack *middle;
	t_stack *bottom;

	if(count == 1)
		return;
	if(count == 2)
	{
		swap(list, sa);
		return;
	}
	top = list->start_a;
	middle = top->next;
	bottom = list->end_a;
	if(top->n < middle->n && top->n < bottom->n)
	{
		rotate(list, ra);
		swap(list, sa);
		reverse(list, rra);
	}
	else if(top->n < middle->n)
	{
		rotate(list, ra);
		swap(list ,sa);
		reverse(list, rra);
		swap(list, sa);
	}
	else if(bottom->n > top->n && bottom->n > middle->n)
		swap(list, sa);
	else
	{
		swap(list, sa);
		rotate(list, sa);
		swap(list, sa);
		rotate(list, sa);
		if(top->n > middle->n)
			swap(list, sa);
	}
	list->sorted_sta = list->start_a;
	list->sorted_ena = list->end_a;
}

int	issorted_a(t_list *list)
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
	return (SUCCESS);
}
