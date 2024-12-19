#include "push_swap.h"

static void sa(t_list *list);
static void sb(t_list *list);
static void ss(t_list *list);

void swap(t_list *list, char c)
{
	if(c == a)
		sa(list);
	else if(c == b)
		sb(list);
	else if(c == s)
		ss(list);
}

static void sa(t_list *list)
{
	t_stack *node1;
	t_stack *node2;

	node1 = list->start_a;
	if(!node1)
		return;
	node2 = node1->next;
	if(!node2)
		return;
	list->start_a = node2;
	node1->next = node2->next;
	node2->next = node1;
	write(1, "sa\n", 3);
}

static void sb(t_list *list)
{
	t_stack *node1;
	t_stack *node2;

	node1 = list->start_b;
	if(!node1)
		return;
	node2 = node1->next;
	if(!node2)
		return;
	list->start_b = node2;
	node1->next = node2->next;
	node2->next = node1;
	write(1, "sb\n", 3);
}

static void ss(t_list *list)
{
	t_stack *node_a1;
	t_stack *node_a2;
	t_stack *node_b1;
	t_stack *node_b2;

	node_a1 = list->start_a;
	node_b1 = list->start_b;
	if(!node_a1 || !node_b1)
		return;
	node_a2 = node_a1->next;
	node_b2 = node_b2->next;
	if(!node_b2 || !node_b2)
		return;
	list->start_a = node_a2;
	node_a1->next = node_a2->next;
	node_a2->next = node_a1;
	list->start_b = node_b2;
	node_b1->next = node_b2->next;
	node_b2->next = node_b1;
	write(1, "ss\n", 3);
}
