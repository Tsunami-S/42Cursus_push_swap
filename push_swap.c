#include "push_swap.h"
void pb_and_ra(t_list *list, t_stack *en_a, t_stack *hikaku);
void pb_and_rra(t_list *list, t_stack *en_a, t_stack *hikaku);
void pa_and_rrb(t_list *list, t_stack *en_b, t_stack *hikaku);
void pa_and_rb(t_list *list, t_stack *en_b, t_stack *hikaku);

void pb_and_ra(t_list *list, t_stack *en_a, t_stack *hikaku)
{
	int count;
	t_stack *first_pb;

//	/**********debug*********/
//	t_stack *nownow = list->start_a;
//	printf("<stack_A>\n");
//	while(nownow)
//	{
//		printf("%d\n", nownow->n);
//		nownow = nownow->next;
//	}
//	nownow = list->start_b;
//	printf("<stack_B>\n");
//	while(nownow)
//	{
//		printf("%d\n", nownow->n);
//		nownow = nownow->next;
//	}
//	/**********debug*********/
	first_pb = NULL;
	while(list->start_a != en_a)
	{
		if(list->start_a->n < hikaku->n)
		{
			push(list, pb);
			if(!first_pb)
				first_pb = list->start_b;
		}
		else
			rotate(list ,ra);
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted_a(list) == ERROR && count > 3 && !list->sorted_num)
		pb_and_ra(list, list->end_a, list->end_a);
	else if(issorted_a(list) == ERROR && count > 3)
		pb_and_rra(list, list->sorted_ena, list->end_a);
	else if(issorted_a(list) == ERROR && count > 0)
		sort_three(list, count);
	if(first_pb)
		pa_and_rb(list, first_pb, list->start_b);
}

void pb_and_rra(t_list *list, t_stack *en_a, t_stack *hikaku)
{
	int count;
	t_stack *first_pb;

//	/**********debug*********/
//	t_stack *nownow = list->start_a;
//	printf("<stack_A>\n");
//	while(nownow)
//	{
//		printf("%d\n", nownow->n);
//		nownow = nownow->next;
//	}
//	nownow = list->start_b;
//	printf("<stack_B>\n");
//	while(nownow)
//	{
//		printf("%d\n", nownow->n);
//		nownow = nownow->next;
//	}
//	/**********debug*********/
	first_pb = NULL;
	while(list->end_a != en_a)
	{
		reverse(list, rra);
		if(list->start_a->n < hikaku->n)
		{
			push(list, pb);
			if(!first_pb)
				first_pb = list->start_b;
		}
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted_a(list) == ERROR && count > 3)
		pb_and_ra(list, list->sorted_sta, list->start_a);
	else if(issorted_a(list) == ERROR && count > 0)
		sort_three(list, count);
	if(first_pb)
		pa_and_rb(list, first_pb, list->start_b);
}

void pa_and_rb(t_list *list, t_stack *en_b, t_stack *hikaku)
{
	int count;
	t_stack *first_rb;
	t_stack *now;

	///**********debug*********/
	//t_stack *nownow = list->start_a;
	//printf("<stack_A>\n");
	//while(nownow)
	//{
	//	printf("%d\n", nownow->n);
	//	nownow = nownow->next;
	//}
	//nownow = list->start_b;
	//printf("<stack_B>\n");
	//while(nownow)
	//{
	//	printf("%d\n", nownow->n);
	//	nownow = nownow->next;
	//}
	///**********debug*********/
	first_rb = NULL;
	while(1)
	{
		now = list->start_b;
		if(list->start_b->n >= hikaku->n)
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
	if(issorted_a(list) == ERROR && count > 3)
		pb_and_ra(list, list->sorted_sta, list->start_a);
	else if(issorted_a(list) == ERROR && count > 0)
		sort_three(list, count);
	if(first_rb)
		pa_and_rrb(list, first_rb, list->end_b);
}

void pa_and_rrb(t_list *list, t_stack *en_b, t_stack *hikaku)
{
	int count;
	t_stack *now;
	t_stack *first_rrb;

//	/**********debug*********/
//	t_stack *nownow = list->start_a;
//	printf("<stack_A>\n");
//	while(nownow)
//	{
//		printf("%d\n", nownow->n);
//		nownow = nownow->next;
//	}
//	nownow = list->start_b;
//	printf("<stack_B>\n");
//	while(nownow)
//	{
//		printf("%d\n", nownow->n);
//		nownow = nownow->next;
//	}
//	/**********debug*********/
	first_rrb = NULL;
	while(1)
	{
		now = list->end_b;
		reverse(list, rrb);
		if(list->start_b->n >= hikaku->n)
			push(list, pa);
		else if(!first_rrb)
			first_rrb = list->start_b;
		if(now == en_b)
			break;
	}
	count = stack_count(list->start_a) - list->sorted_num;
	if(issorted_a(list) == ERROR && count > 3)
		pb_and_ra(list, list->sorted_sta, list->start_a);
	else if(issorted_a(list) == ERROR && count > 0)
		sort_three(list, count);
	if(first_rrb)
		pa_and_rb(list, first_rrb, list->start_b);
}
