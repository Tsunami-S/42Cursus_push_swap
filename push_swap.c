#include "push_swap.h"
static void sort_three(t_list *list, int count);
int stack_count(t_stack *stack);

static int	issorted_a(t_list *list)
{
	t_stack	*now;

	now = list->start_a;
	if (!now)
		return (SUCCESS);
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
void	push_swap(t_list *list, t_stack *doko, t_stack *hikaku, int *sortnum)
{
	t_stack *first_pb = NULL;
	t_stack *tmp;

	if(issorted_a(list) == SUCCESS && !list->start_b)
		return;
	while(list->start_a != doko)
	{
		if(list->start_a->n < hikaku->n)
		{
			if(!first_pb)
				first_pb = list->start_a;
			push(list, pb);
		}
		else
			rotate(list, ra);
	}
	int count = stack_count(list->start_a);
	if(issorted_a(list) == ERROR && !*sortnum && count - *sortnum > 3)
		push_swap(list, list->end_a, list->end_a, sortnum);
	else if(issorted_a(list) == ERROR && count - *sortnum > 3 )
	{
		tmp = list->sorted_ena->next;
		t_stack *tmp2 = NULL;
		while(list->end_a != list->sorted_ena)
		{
			reverse(list, rra);
			if(tmp->n >= list->start_a->n)
			{
				if(!tmp2)
					tmp2 = list->start_a;
				push(list, pb);
			}
		}
		if(issorted_a(list) == ERROR)
			push_swap(list, list->sorted_sta, list->start_a, sortnum);
		tmp = list->start_a;
		if(tmp2)
		{
			while(list->start_a != tmp2)
				push(list, pa);
			push_swap(list, tmp, list->start_a->next, sortnum);
		}
	}
	count = stack_count(list->start_a);
	if(count - *sortnum <= 3 && issorted_a(list) == ERROR)
	{
		while(list->sorted_ena && list->end_a != list->sorted_ena)
				reverse(list, rra);
		sort_three(list, count - *sortnum);
	}
	if(issorted_a(list) == SUCCESS)
		*sortnum = stack_count(list->start_a);
	if(first_pb)
	{
		tmp = list->start_b;
		while(list->start_a != first_pb)
			push(list, pa);
		if(issorted_a(list) == ERROR)
			push_swap(list, list->sorted_sta, list->start_a, sortnum);
	}
}

int stack_count(t_stack *stack)
{
	int count;

	count = 1;
	while(stack)
	{
		stack = stack->next;
		count++;
	}
	return count;
}

static void sort_three(t_list *list, int count)
{
	t_stack *top;
	t_stack *middle;
	t_stack *bottom;

//	printf("IN, count: %d\n", count);
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
