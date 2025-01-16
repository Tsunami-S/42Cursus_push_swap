#include "push_swap.h"

void	make_stack_a_smaller(t_stack *stacks, int start_size)
{
	t_count	act_count;

	split_stack_a_top(stacks, start_size, &act_count);
	if (act_count.to_a_bottom <= 5)
		sort_few_elems(stacks, act_count.to_a_bottom);
	else if (is_stack_sorted(stacks->start_a, act_count.to_a_bottom) != ASCENDING)
		make_stack_a_smaller(stacks, act_count.to_a_bottom);
	sort_stack_b_top(stacks, act_count.to_b_top);
	sort_stack_b_bottom(stacks, act_count.to_b_bottom);
}

void	sort_stack_a_top(t_stack *stacks, int start_size)
{
	t_count	act_count;

	if (is_stack_sorted(stacks->start_a, start_size) == ASCENDING)
		return ;
	else if (start_size <= 3)
		sort_few_elems(stacks, start_size);
	else
	{
		split_stack_a_top(stacks, start_size, &act_count);
		sort_stack_a_bottom(stacks, act_count.to_a_bottom);
		sort_stack_b_top(stacks, act_count.to_b_top);
		sort_stack_b_bottom(stacks, act_count.to_b_bottom);
	}
}

void	sort_stack_a_bottom(t_stack *stacks, int start_size)
{
	t_count	act_count;

	if (start_size <= 3)
	{
		consecutive_cmds(stacks, rra, start_size);
		sort_few_elems(stacks, start_size);
	}
	else
	{
		split_stack_a_bottom(stacks, start_size, &act_count);
		sort_stack_a_top(stacks, act_count.to_a_top);
		sort_stack_b_top(stacks, act_count.to_b_top);
		sort_stack_b_bottom(stacks, act_count.to_b_bottom);
	}
}

void	sort_stack_b_top(t_stack *stacks, int count)
{
	t_count	act_count;

	if (count <= 3)
	{
		consecutive_cmds(stacks, pa, count);
		sort_few_elems(stacks, count);
	}
	else if (is_stack_sorted(stacks->start_b, count) == DESCENDING)
		consecutive_cmds(stacks, pa, count);
	else
	{
		split_stack_b_top(stacks, count, &act_count);
		sort_stack_a_top(stacks, act_count.to_a_top);
		sort_stack_a_bottom(stacks, act_count.to_a_bottom);
		sort_stack_b_bottom(stacks, act_count.to_b_bottom);
	}
}

void	sort_stack_b_bottom(t_stack *stacks, int count)
{
	t_order	order;
	t_count	act_count;

	order = is_stack_sorted(back_to_prev(stacks->end_b, count), count);
	if (count <= 3)
	{
		consecutive_cmds(stacks, rrb, count);
		consecutive_cmds(stacks, pa, count);
		sort_few_elems(stacks, count);
	}
	else if (order == ASCENDING)
	{
		while (count--)
		{
			compress_cmds(stacks, rrb);
			compress_cmds(stacks, pa);
		}
	}
	else if (order == DESCENDING)
	{
		consecutive_cmds(stacks, rrb, count);
		consecutive_cmds(stacks, pa, count);
	}
	else
	{
		split_stack_b_bottom(stacks, count, &act_count);
		sort_stack_a_top(stacks, act_count.to_a_top);
		sort_stack_a_bottom(stacks, act_count.to_a_bottom);
		sort_stack_b_top(stacks, act_count.to_b_top);
	}
}
