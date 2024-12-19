#include "push_swap.h"

void push_swap(t_list *stack_a, t_list *stack_b)
{


}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	if(argc < 2)
		return error(), 0;
	else if(argc == 2)
		stack_a = init_stack_from_one(argv[1]);
	else
		stack_a = init_stack_from_args(argc, **argv);
	stack_b = NULL;
	push_swap(a, b);
	return 0;
}
