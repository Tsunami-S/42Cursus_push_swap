#include "push_swap.h"
void pb_and_ra(t_list *list, t_stack *en_a, t_stack *min, t_stack *max);
void pa_and_rb(t_list *list, t_stack *en_b, t_stack *min, t_stack *max);
void pa_and_rrb(t_list *list, t_stack *en_b, t_stack *min, t_stack *max);
void pb_and_rra(t_list *list, t_stack *en_a, t_stack *min, t_stack *max);

int	make_average(t_stack *start, t_stack *end)
{
	long long total;
	int i;

	total = 0;
	i = 1;
	while(start != end)
	{
		total += start->n;
		start = start->next;
		i++;
	}
	total += start->n;
	return total / i;
}

void push_swap(t_list *list)
{
	int count;

	count = stack_count(list->start_a);
	ash(list, init);
	if(count < 5)
	{
		if(issorted(list) == ERROR)
			sort_six(list, count);
		ash(list, none);
		return;
	}
	pb_and_ra(list, NULL, list->start_a, list->end_a);
	ash(list, none);
}

void pb_and_ra(t_list *list, t_stack *en_a, t_stack *min, t_stack *max)
{
	int count;
	int medium;
	t_stack *first_pb;

	first_pb = NULL;
	medium =  make_average(min, max);
	while(list->start_a != en_a)
	{
		if(list->start_a->n < medium)
		{
			ash(list, pb);
			if(!first_pb)
				first_pb = list->start_b;
		}
		else
		{
			if(list->start_a == list->end_a)
				break;
			ash(list ,ra);
			if(!en_a)
				en_a = list->end_a;
		}
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted(list) == ERROR && count > 4 && !list->sorted_num)
		pb_and_ra(list, NULL, list->start_a, list->end_a);
	else if(issorted(list) == ERROR && count > 4)
		pb_and_rra(list, list->sorted_ena, list->sorted_ena->next, list->end_a);
	else if(issorted(list) == ERROR && count > 0)
		sort_six(list, count);
	if(first_pb)
		pa_and_rb(list, first_pb, list->start_b, first_pb);
}

void pb_and_rra(t_list *list, t_stack *en_a, t_stack *min, t_stack *max)
{
	int count;
	int medium;
	t_stack *first_pb;

	medium =  make_average(min, max);
	first_pb = NULL;
	while(list->end_a != en_a)
	{
		ash(list, rra);
		if(list->start_a->n < medium)
		{
			ash(list, pb);
			if(!first_pb)
				first_pb = list->start_b;
		}
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted(list) == ERROR && count > 4)
		pb_and_ra(list, list->sorted_sta, list->start_a, list->sorted_sta->prev);
	else if(issorted(list) == ERROR && count > 0)
		sort_six(list, count);
	if(first_pb)
		pa_and_rb(list, first_pb, list->start_b, first_pb);
}

void pa_and_rb(t_list *list, t_stack *en_b, t_stack *min, t_stack *max)
{
	int medium;
	int count;
	t_stack *first_rb;
	t_stack *now;

	medium =  make_average(min, max);
	first_rb = NULL;
	while(1)
	{
		now = list->start_b;
		if(list->start_b->n >= medium)
			ash(list, pa);
		else
		{
			if(!first_rb)
				first_rb = list->start_b;
			ash(list, rb);
		}
		if(now == en_b)
			break;
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted(list) == ERROR && count > 4)
		pb_and_ra(list, list->sorted_sta, list->start_a, list->sorted_sta->prev);
	else if(issorted(list) == ERROR && count > 0)
		sort_six(list, count);
	if(first_rb)
		pa_and_rrb(list, first_rb, first_rb, list->end_b);
}

void pa_and_rrb(t_list *list, t_stack *en_b, t_stack *min, t_stack *max)
{
	int medium;
	int count;
	t_stack *now;
	t_stack *first_rrb;

	medium =  make_average(min, max);
	first_rrb = NULL;
	while(1)
	{
		now = list->end_b;
		if(list->start_b != list->end_b)
			ash(list, rrb);
		if(list->start_b->n >= medium)
			ash(list, pa);
		else if(!first_rrb)
			first_rrb = list->start_b;
		if(now == en_b)
			break;
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted(list) == ERROR && count > 4)
		pb_and_ra(list, list->sorted_sta, list->start_a, list->sorted_sta->prev);
	else if(issorted(list) == ERROR && count > 0)
		sort_six(list, count);
	if(first_rrb)
		pa_and_rb(list, first_rrb, list->start_b, first_rrb);
}
