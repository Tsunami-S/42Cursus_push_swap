#include "push_swap.h"

static void pa(t_list *list);
static void pb(t_list *list);

void push(t_list *list, char c)
{
	if(c == a)
		pa(list);
	else if(c == b)
		pb(list);
}

static void pa(t_list *list)
{
	t_stack *node_a;
	t_stack *node_b;

	node_a = list->start_a;
	node_b = list->start_b;
	if(!node_b)
		return;
	list->start_b = node_b->next;
	if(!list->start_b)
		list->end_b = NULL;
	node_b->next = node_a;
	list->start_a = node_b;
	write(1, "pa\n", 3);
}

static void pb(t_list *list)
{
	t_stack *node_a;
	t_stack *node_b;

	node_a = list->start_a;
	node_b = list->start_b;
	if(!node_a)
		return;
	list->start_a = node_a->next;
	if(!list->start_a)
		list->end_a = NULL;
	node_a->next = node_b;
	list->start_b = node_a;
	write(1, "pa\n", 3);
}
