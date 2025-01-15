#include "push_swap.h"

static void	push_to_a(t_stack *stacks);
static void	push_to_b(t_stack *stacks);

void	push(t_stack *stacks, t_act act)
{
	if (act == pa)
		push_to_a(stacks);
	else if (act == pb)
		push_to_b(stacks);
}

static void	push_to_a(t_stack *stacks)
{
	t_elem	*node_a;
	t_elem	*node_b;

	if (!stacks->start_b)
		return ;
	node_a = stacks->start_a;
	node_b = stacks->start_b;
	stacks->start_b = node_b->next;
	if (stacks->start_b)
		stacks->start_b->prev = NULL;
	else
		stacks->end_b = NULL;
	node_b->next = node_a;
	node_b->prev = NULL;
	if (node_a)
		node_a->prev = node_b;
	else
		stacks->end_a = node_b;
	stacks->start_a = node_b;
}

static void	push_to_b(t_stack *stacks)
{
	t_elem	*node_a;
	t_elem	*node_b;

	node_a = stacks->start_a;
	node_b = stacks->start_b;
	if (!node_a)
		return ;
	stacks->start_a = node_a->next;
	if (!stacks->start_a)
		stacks->end_a = NULL;
	else
		node_a->next->prev = NULL;
	node_a->next = node_b;
	node_a->prev = NULL;
	if (node_b)
		node_b->prev = node_a;
	else
		stacks->end_b = node_a;
	stacks->start_b = node_a;
}
