#include "push_swap.h"

void delete_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_list *tmp;

	while(stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	while(stack_b)
	{
		tmp = stack_b;
		stack_b = stack_b->next;
		free(tmp);
	}
}
