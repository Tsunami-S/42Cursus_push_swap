#include "push_swap.h"

static void list_init(t_list *list);

void push_swap(t_stack *stack_a, t_stack *stack_b, t_list *list)
{
	while(!ft_issorted(a, b))
	{
		if()
			sa
		else if()
			sb
		else if()
			ss
		else if()
			pa
		else if()
			pb
		else if()
			pp
		else if()
			ra
		else if()
			rb
		else if()
			rr
		else if()
			rra
		else if()
			rrb
		else if()
			rrr
		}
}

static void list_init(t_list *list)
{
	list->start_a = NULL;
	list->start_b = NULL;
	list->end_a = NULL;
	list->end_b = NULL;
}

int main(int argc, char **argv)
{
	t_list *list;
	t_stack *stack_a;
	t_stack *stack_b;

	list_init(list);
	if(argc < 2)
		return error(), 0;
	else if(argc == 2)
		stack_a = init_stack_from_one(argv[1], list);
	else
		stack_a = init_stack_from_args(argc, argv, list);
	stack_b = NULL;
	push_swap(a, b, list);
	return 0;
}
