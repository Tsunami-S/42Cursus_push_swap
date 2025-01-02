#include "push_swap.h"

void push_swap(t_list *list)
{
	int count;
	int max;
	int min;

	count = stack_count(list->start_a);
	if(count < 7)
	{
		if(issorted(list) == ERROR)
			sort_six(list, count);
		return;
	}
	search_max_and_min(list->start_a, &max, &min);
	pb_and_ra(list, NULL, min, max);
}

void pb_and_ra(t_list *list, t_stack *en_a, int min, int max)
{
	int count;
	int medium;
	t_stack *first_pb;

	first_pb = NULL;
	medium = (max + min) / 2;
	while(list->start_a != en_a)
	{
		if(list->start_a->n < medium)
		{
			push(list, pb);
			if(!first_pb)
				first_pb = list->start_b;
		}
		else
		{
			rotate(list ,ra);
			if(!en_a)
				en_a = list->end_a;
		}
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted(list) == ERROR && count > 6 && !list->sorted_num)
		pb_and_ra(list, NULL, medium, max);
	else if(issorted(list) == ERROR && count > 6)
		pb_and_rra(list, list->sorted_ena, medium, max);
	else if(issorted(list) == ERROR && count > 0)
		sort_six(list, count);
	if(first_pb)
		pa_and_rb(list, first_pb, min, medium);
}

void pb_and_rra(t_list *list, t_stack *en_a, int min, int max)
{
	int count;
	int medium;
	t_stack *first_pb;

	medium = (max + min) / 2;
	first_pb = NULL;
	while(list->end_a != en_a)
	{
		reverse(list, rra);
		if(list->start_a->n < medium)
		{
			push(list, pb);
			if(!first_pb)
				first_pb = list->start_b;
		}
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted(list) == ERROR && count > 6)
		pb_and_ra(list, list->sorted_sta, medium, max);
	else if(issorted(list) == ERROR && count > 0)
		sort_six(list, count);
	if(first_pb)
		pa_and_rb(list, first_pb, min, medium);
}

void pa_and_rb(t_list *list, t_stack *en_b, int min, int max)
{
	int medium;
	int count;
	t_stack *first_rb;
	t_stack *now;

	medium = (max + min) / 2;
	first_rb = NULL;
	while(1)
	{
		now = list->start_b;
		if(list->start_b->n >= medium)
			push(list, pa);
		else
		{
			if(!first_rb)
				first_rb = list->start_b;
			rotate(list, rb);
		}
		if(now == en_b)
			break;
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted(list) == ERROR && count > 6)
		pb_and_ra(list, list->sorted_sta, medium, max);
	else if(issorted(list) == ERROR && count > 0)
		sort_six(list, count);
	if(first_rb)
		pa_and_rrb(list, first_rb, min, medium);
}

void pa_and_rrb(t_list *list, t_stack *en_b, int min, int max)
{
	int medium;
	int count;
	t_stack *now;
	t_stack *first_rrb;

	medium = (max + min) / 2;
	first_rrb = NULL;
	while(1)
	{
		now = list->end_b;
		reverse(list, rrb);
		if(list->start_b->n >= medium)
			push(list, pa);
		else if(!first_rrb)
			first_rrb = list->start_b;
		if(now == en_b)
			break;
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted(list) == ERROR && count > 6)
		pb_and_ra(list, list->sorted_sta, medium, max);
	else if(issorted(list) == ERROR && count > 0)
		sort_six(list, count);
	if(first_rrb)
		pa_and_rb(list, first_rrb, min, medium);
}
