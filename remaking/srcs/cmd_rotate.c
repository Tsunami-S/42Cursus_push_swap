#include "push_swap.h"

static void	rotate_a(t_stack *stacks);
static void	rotate_b(t_stack *stacks);

void	rotate(t_stack *stacks, t_act act)
{
	if (act == ra)
		rotate_a(stacks);
	else if (act == rb)
		rotate_b(stacks);
	else if (act == rr)
	{
		rotate_a(stacks);
		rotate_b(stacks);
	}
}

static void	rotate_a(t_stack *stacks)
{
	t_elem	*node1;
	t_elem	*node2;

	node1 = stacks->start_a;
	node2 = stacks->end_a;
	if (!node1 || !node2 || node1 == node2)
		return ;
	stacks->start_a = node1->next;
	node1->next->prev = NULL;
	node2->next = node1;
	node1->next = NULL;
	node1->prev = node2;
	stacks->end_a = node1;
	return ;
}

static void	rotate_b(t_stack *stacks)
{
	t_elem	*node1;
	t_elem	*node2;

	node1 = stacks->start_b;
	node2 = stacks->end_b;
	if (!node1 || !node2 || node1 == node2)
		return ;
	stacks->start_b = node1->next;
	node1->next->prev = NULL;
	node2->next = node1;
	node1->next = NULL;
	node1->prev = node2;
	stacks->end_b = node1;
	return ;
}
