#include "push_swap.h"

static void	swap_a(t_stack *stacks);
static void	swap_b(t_stack *stacks);

void	swap(t_stack *stacks, t_act act)
{
	if (act == sa)
		swap_a(stacks);
	else if (act == sb)
		swap_b(stacks);
	else if (act == ss)
	{
		swap_a(stacks);
		swap_b(stacks);
	}
}

static void	swap_a(t_stack *stacks)
{
	t_elem	*node1;
	t_elem	*node2;

	node1 = stacks->start_a;
	if (!node1)
		return ;
	node2 = node1->next;
	if (!node2)
		return ;
	stacks->start_a = node2;
	if (stacks->end_a == node2)
		stacks->end_a = node1;
	node1->next = node2->next;
	if (node1->next)
		node1->next->prev = node1;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	return ;
}

static void	swap_b(t_stack *stacks)
{
	t_elem	*node1;
	t_elem	*node2;

	node1 = stacks->start_b;
	if (!node1)
		return ;
	node2 = node1->next;
	if (!node2)
		return ;
	stacks->start_b = node2;
	if (stacks->end_b == node2)
		stacks->end_b = node1;
	node1->next = node2->next;
	if (node1->next)
		node1->next->prev = node1;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	return ;
}
