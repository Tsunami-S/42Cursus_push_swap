#include "push_swap.h"

void	push_swap(t_stack *stacks)
{
	int	count;

	count = count_elems(stacks->start_a, stacks->end_a);
	if (count == 1 || is_stack_sorted(stacks->start_a, count) == ASCENDING)
		return ;
	else if (count <= 5)
		sort_few_elems(stacks, count);
	else
		make_stack_a_smaller(stacks, count);
	compress_cmds(stacks, none);
}
