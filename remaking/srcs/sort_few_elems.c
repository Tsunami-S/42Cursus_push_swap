#include "push_swap.h"

static void	sort_three(t_stack *stacks);
static void	sort_four(t_stack *stacks);
static void	sort_five(t_stack *stacks);
static void	merge(t_stack *stacks, int len_a, int len_b);

void	sort_few_elems(t_stack *stacks, int count)
{
	if (count <= 1 || is_stack_sorted(stacks->start_a, count) == ASCENDING)
		return ;
	if (count == 2)
		compress_cmds(stacks, sa);
	else if (count == 3)
		sort_three(stacks);
	else if (count == 4)
		sort_four(stacks);
	else if (count == 5)
		sort_five(stacks);
}

static void	sort_three(t_stack *stacks)
{
	t_elem	*st_a;

	st_a = stacks->start_a;
	if (count_elems(stacks->start_a, stacks->end_a) == 3)
	{
		if (st_a->next->n < st_a->n && stacks->end_a->n < st_a->n)
			compress_cmds(stacks, ra);
		else if (st_a->n < st_a->next->n && stacks->end_a->n < st_a->next->n)
			compress_cmds(stacks, rra);
		if (stacks->start_a->n > stacks->start_a->next->n)
			compress_cmds(stacks, sa);
	}
	else
	{
		if (stacks->start_a->n > stacks->start_a->next->n)
			compress_cmds(stacks, sa);
		compress_cmds(stacks, pb);
		if (stacks->start_a->n > stacks->start_a->next->n)
			compress_cmds(stacks, sa);
		compress_cmds(stacks, pa);
		if (stacks->start_a->n > stacks->start_a->next->n)
			compress_cmds(stacks, sa);
	}
}

static void	sort_four(t_stack *stacks)
{
	t_elem	*st_a;

	if (stacks->start_a->n > stacks->start_a->next->n)
		compress_cmds(stacks, sa);
	if (is_stack_sorted(stacks->start_a, 4) == ASCENDING)
		return ;
	st_a = stacks->start_a;
	if (st_a->n < st_a->next->next->n || st_a->n < st_a->next->next->next->n)
	{
		compress_cmds(stacks, pb);
		sort_three(stacks);
		compress_cmds(stacks, pa);
	}
	else
	{
		compress_cmds(stacks, ra);
		compress_cmds(stacks, sa);
		compress_cmds(stacks, pb);
		compress_cmds(stacks, rra);
		sort_three(stacks);
		compress_cmds(stacks, pa);
	}
	if (stacks->start_a->n > stacks->start_a->next->n)
		compress_cmds(stacks, sa);
}

static void	sort_five(t_stack *stacks)
{
	t_elem	*st_a;

	if (stacks->start_a->n > stacks->start_a->next->n)
		compress_cmds(stacks, sa);
	if (is_stack_sorted(stacks->start_a, 5) == ASCENDING)
		return ;
	compress_cmds(stacks, pb);
	compress_cmds(stacks, pb);
	sort_three(stacks);
	st_a = stacks->start_a;
	if (st_a->n > stacks->start_b->n)
	{
		compress_cmds(stacks, pa);
		compress_cmds(stacks, pa);
		return ;
	}
	merge(stacks, 3, 2);
}

static void	merge(t_stack *stacks, int len_a, int len_b)
{
	while (len_a && len_b)
	{
		if (len_a && stacks->end_a->n > stacks->start_b->n)
		{
			compress_cmds(stacks, rra);
			len_a--;
		}
		else if (len_b && stacks->end_a->n < stacks->start_b->n)
		{
			compress_cmds(stacks, pa);
			len_b--;
		}
	}
	while (!len_a && len_b)
	{
		compress_cmds(stacks, pa);
		len_b--;
	}
	while (!len_b && len_a)
	{
		compress_cmds(stacks, rra);
		len_a--;
	}
}
