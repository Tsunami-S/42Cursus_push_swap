#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;

	if (argc < 2)
		return (0);
	init_stacks(&stacks, argc, argv);
	push_swap(&stacks);
	free_stacks(&stacks, SUCCESS);
	return (0);
}

///**********debug*********/
// t_elem *now = stacks.start_a;
// printf("<stack_A>\n");
// while(now)
//{
//	printf("%d\n", now->n);
//	now = now->next;
//}
// now = stacks.start_b;
// printf("<stack_B>\n");
// while(now)
//{
//	printf("%d\n", now->n);
//	now = now->next;
//}
///**********debug*********/
