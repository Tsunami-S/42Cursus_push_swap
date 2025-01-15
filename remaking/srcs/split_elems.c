#include "push_swap.h"

void	split_stack_a_top(t_stack *stacks, int size, t_count *act_count)
{
	int	large_pivot;
	int	small_pivot;

	init_act_count(act_count);
	make_pivots(stacks->start_a, size, &large_pivot, &small_pivot);
	while (size--)
	{
		if (stacks->start_a->n > large_pivot)
		{
			compress_cmds(stacks, ra);
			act_count->to_a_bottom++;
		}
		else
		{
			compress_cmds(stacks, pb);
			if (stacks->start_b->n < small_pivot)
			{
				compress_cmds(stacks, rb);
				act_count->to_b_bottom++;
			}
			else
				act_count->to_b_top++;
		}
	}
}

void	split_stack_a_bottom(t_stack *stacks, int size, t_count *act_count)
{
	int	large_pivot;
	int	small_pivot;

	init_act_count(act_count);
	make_pivots(back_to_prev(stacks->end_a, size), size, &large_pivot,
		&small_pivot);
	while (size--)
	{
		compress_cmds(stacks, rra);
		if (stacks->start_a->n < large_pivot)
		{
			compress_cmds(stacks, pb);
			if (stacks->start_b->n < small_pivot)
			{
				compress_cmds(stacks, rb);
				act_count->to_b_bottom++;
			}
			else
				act_count->to_b_top++;
		}
		else
			act_count->to_a_top++;
	}
}

void	split_stack_b_top(t_stack *stacks, int size, t_count *act_count)
{
	int	large_pivot;
	int	small_pivot;

	init_act_count(act_count);
	make_pivots(stacks->start_b, size, &large_pivot, &small_pivot);
	while (size--)
	{
		if (stacks->start_b->n > small_pivot)
		{
			compress_cmds(stacks, pa);
			if (stacks->start_a->n < large_pivot)
			{
				compress_cmds(stacks, ra);
				act_count->to_a_bottom++;
			}
			else
				act_count->to_a_top++;
		}
		else
		{
			compress_cmds(stacks, rb);
			act_count->to_b_bottom++;
		}
	}
}

void	split_stack_b_bottom(t_stack *stacks, int size, t_count *act_count)
{
	int	large_pivot;
	int	small_pivot;

	init_act_count(act_count);
	make_pivots(back_to_prev(stacks->end_b, size), size, &large_pivot,
		&small_pivot);
	while (size--)
	{
		compress_cmds(stacks, rrb);
		if (stacks->start_b->n > small_pivot)
		{
			compress_cmds(stacks, pa);
			if (stacks->start_a->n < large_pivot)
			{
				compress_cmds(stacks, ra);
				act_count->to_a_bottom++;
			}
			else
				act_count->to_a_top++;
		}
		else
			act_count->to_b_top++;
	}
}
