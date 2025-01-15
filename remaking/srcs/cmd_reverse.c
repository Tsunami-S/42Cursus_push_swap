#include "push_swap.h"

static void	reverse_a(t_stack *stacks);
static void	reverse_b(t_stack *stacks);

void	reverse(t_stack *stacks, t_act act)
{
	if (act == rra)
		reverse_a(stacks);
	else if (act == rrb)
		reverse_b(stacks);
	else if (act == rrr)
	{
		reverse_a(stacks);
		reverse_b(stacks);
	}
}

static void	reverse_a(t_stack *stacks)
{
	t_elem	*node1;
	t_elem	*node2;

	node1 = stacks->start_a;
	node2 = stacks->end_a;
	if (!node1 || !node2 || node1 == node2)
		return ;
	stacks->start_a = node2;
	stacks->end_a = node2->prev;
	node2->prev->next = NULL;
	node2->next = node1;
	node2->prev = NULL;
	node1->prev = node2;
	return ;
}

static void	reverse_b(t_stack *stacks)
{
	t_elem	*node1;
	t_elem	*node2;

	node1 = stacks->start_b;
	node2 = stacks->end_b;
	if (!node1 || !node2 || node1 == node2)
		return ;
	stacks->start_b = node2;
	stacks->end_b = node2->prev;
	node2->prev->next = NULL;
	node2->next = node1;
	node2->prev = NULL;
	node1->prev = node2;
	return ;
}
