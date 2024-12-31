#include "push_swap.h"
void back_to_a(t_list *list, t_stack *en_b);

void	push_swap(t_list *list, t_stack *en_a, t_stack *hikaku)
{
	int count;
	t_stack *first_pb;

	if(issorted_a(list) == SUCCESS && !list->start_b)
		return;
	first_pb = NULL;
	while(list->start_a != en_a)
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
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted_a(list) == ERROR && !list->sorted_num && count > 3)
		push_swap(list, list->end_a, list->end_a);
	else if(issorted_a(list) == ERROR && count > 3)
	{
		if(count > list->sorted_num)
		{
			while(list->sorted_ena != list->end_a)
				rotate(list, ra);
		}
		else
		{
			while(list->sorted_ena != list->end_a)
				reverse(list, rra);
		}
		push_swap(list, list->sorted_sta, list->end_a);
	}
	else if(issorted_a(list) == ERROR)
	{
		while(list->sorted_ena && list->end_a != list->sorted_ena)
			reverse(list, rra);
		sort_three(list, count);
	}
	if(first_pb)
		back_to_a(list, first_pb);
}

void back_to_a(t_list *list, t_stack *en_b)
{
	int count;
	t_stack *first_rb;
	t_stack *hikaku;

	while(en_b)
	{
		first_rb = NULL;
		hikaku = list->start_b;
		while(list->start_a != en_b && list->end_b != en_b)
		{
			if(list->start_b->n >= hikaku->n)
				push(list, pa);
			else
			{
				if(!first_rb)
					first_rb = list->start_b;
				rotate(list, rb);
			}
		}
		en_b = NULL;
		count = stack_count(list->start_a) - list->sorted_num;
		if(issorted_a(list) == ERROR && count > 3)
			push_swap(list, list->sorted_sta, list->start_a);
		else if(issorted_a(list) == ERROR)
			sort_three(list, count);
		if(first_rb)
		{
			hikaku = list->end_b;
			while(list->start_a != first_rb && list->start_b != first_rb)
			{
				reverse(list, rrb);
				if(list->start_b->n >= hikaku->n)
					push(list, pa);
				else if(!en_b)
					en_b = list->start_b;
			}
			count = stack_count(list->start_a) - list->sorted_num;
			if(issorted_a(list) == ERROR && count > 3)
				push_swap(list, list->sorted_sta, list->start_a);
			else if(issorted_a(list) == ERROR)
				sort_three(list, count);
		}
	}
}
