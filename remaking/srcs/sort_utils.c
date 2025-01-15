#include "push_swap.h"

int	count_elems(t_elem *start, t_elem *end)
{
	int	count;

	if (!start)
		return (0);
	count = 1;
	while (start != end)
	{
		count++;
		start = start->next;
	}
	return (count);
}

void	init_act_count(t_count *act_count)
{
	act_count->to_a_top = 0;
	act_count->to_b_top = 0;
	act_count->to_a_bottom = 0;
	act_count->to_b_bottom = 0;
}

t_elem	*back_to_prev(t_elem *start, int count)
{
	t_elem	*prev_node;

	if (count == 0)
		return (NULL);
	if (count == 1)
		return (start);
	prev_node = start;
	while (--count)
		prev_node = prev_node->prev;
	return (prev_node);
}

t_order	is_stack_sorted(t_elem *start, int count)
{
	t_elem	*now;
	int		i;
	int		ascending_count;
	int		descending_count;

	if (count == 0 || count == 1)
		return (ASCENDING);
	i = 1;
	ascending_count = 1;
	descending_count = 1;
	now = start;
	while (i++ < count)
	{
		if (now->n < now->next->n)
			ascending_count++;
		else if (now->n > now->next->n)
			descending_count++;
		now = now->next;
	}
	if (ascending_count == count)
		return (ASCENDING);
	else if (descending_count == count)
		return (DESCENDING);
	return (UNORDERED);
}

void	make_pivots(t_elem *start, int size, int *large, int *small)
{
	t_elem		*now;
	long long	total;
	int			count;

	total = 0;
	count = 0;
	now = start;
	while (count++ < size)
	{
		total += now->n;
		now = now->next;
	}
	*large = total / size;
	count = 0;
	now = start;
	while (size--)
	{
		if (now->n > *large)
			total -= now->n;
		else
			count++;
		now = now->next;
	}
	*small = total / count;
}
