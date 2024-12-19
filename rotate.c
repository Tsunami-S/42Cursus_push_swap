#include "push_swap.h"

void rotate(t_list *list, char c)
{
	if(c == a)
		ra(list);
	else if(c == b)
		rb(list);
	else if(c == r)
		rr(list);
}

void ra(t_list *list)
{
	t_stack *node1;
	t_stack *node2;

	node1 = list->start_a;
	node2 = list->end_a;
	list->start_a = node1->next;
	node2->next = node1;

