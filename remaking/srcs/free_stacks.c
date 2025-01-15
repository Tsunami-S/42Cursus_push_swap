#include "push_swap.h"

void	free_stacks(t_stack *stacks, t_check check)
{
	t_elem	*node_a;
	t_elem	*node_b;
	t_elem	*tmp;

	node_a = stacks->start_a;
	node_b = stacks->start_b;
	while (node_a)
	{
		tmp = node_a;
		node_a = node_a->next;
		free(tmp);
	}
	while (node_b)
	{
		tmp = node_b;
		node_b = node_b->next;
		free(tmp);
	}
	if(check == ERROR)
	{
		write(STDERR_FILENO, "ERROR\n", 6);
		exit(EXIT_FAILURE);
	}
}
