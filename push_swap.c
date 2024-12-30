#include "push_swap.h"
void back_to_a(t_list *list, t_stack *en_b, int *sortnum);

void	push_swap(t_list *list, t_stack *en_a, t_stack *hikaku, int *sortnum)
{
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
	if(issorted_a(list) == ERROR && !*sortnum && stack_count(list->start_a) - *sortnum > 3)
		push_swap(list, list->end_a, list->end_a, sortnum);
	else if(issorted_a(list) == ERROR && stack_count(list->start_a) - *sortnum > 3)
		push_swap(list, list->sorted_sta, list->start_a, sortnum);
	else if(issorted_a(list) == ERROR)
	{
		while(list->sorted_ena && list->end_a != list->sorted_ena)
			reverse(list, rra);
		sort_three(list, stack_count(list->start_a) - *sortnum);
	}
	if(issorted_a(list) == SUCCESS)
		*sortnum = stack_count(list->start_a);
	if(first_pb)
		back_to_a(list, first_pb, sortnum);
}

void back_to_a(t_list *list, t_stack *en_b, int *sortnum)
{
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
		if(issorted_a(list) == ERROR && stack_count(list->start_a) - *sortnum > 3)
			push_swap(list, list->sorted_sta, list->start_a, sortnum);
		else if(issorted_a(list) == ERROR)
			sort_three(list, stack_count(list->start_a) - *sortnum);
		if(issorted_a(list) == SUCCESS)
			*sortnum = stack_count(list->start_a);
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
			if(issorted_a(list) == ERROR && stack_count(list->start_a) - *sortnum > 3)
				push_swap(list, list->sorted_sta, list->start_a, sortnum);
			else if(issorted_a(list) == ERROR)
				sort_three(list, stack_count(list->start_a) - *sortnum);
			if(issorted_a(list) == SUCCESS)
				*sortnum = stack_count(list->start_a);
		}
	}
}
