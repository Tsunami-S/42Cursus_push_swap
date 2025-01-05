#include "../inc/push_swap.h"

void sort_a_bottom(t_list *list, int start_size)
{
	int large_pivot;
	int small_pivot;
	int rra_count;
	int pb_count;
	int rb_count;

	if(start_size == 0)
		return;
	if(start_size == 1)
	{
		compress_cmds(list, rra);
		return;
	}
	else if(start_size == 2)
	{
		compress_cmds(list, rra);
		compress_cmds(list, rra);
		if(list->start_a->n > list->start_a->next->n)
			compress_cmds(list, sa);
		return;
	}
	else if(start_size == 3)
	{
		sort_small_a_bottom(list, start_size);
		return;
	}
	make_pivot_go_prev(list->end_a, start_size, &large_pivot, &small_pivot);
	rra_count = 0;
	pb_count = 0;
	rb_count = 0;
	while(start_size--)
	{
		compress_cmds(list, rra);
		rra_count++;
		if (list->start_a->n < large_pivot)
		{
			pb_count++;
			compress_cmds(list, pb);
			if(list->start_b->n < small_pivot)
			{
				compress_cmds(list, rb);
				rb_count++;
			}
		}
	}
	if(issorted_a(list) == ERROR && rra_count - pb_count > 3)
		sort_a_top(list, rra_count - pb_count);
	else if(issorted_a(list) == ERROR)
		sort_small_stack(list, rra_count - pb_count);
	sort_b_top(list, pb_count - rb_count);
	sort_b_bottom(list, rb_count);
}

void sort_a_top(t_list *list, int start_size)
{
	int large_pivot;
	int small_pivot;
	int ra_count;
	int pb_count;
	int rb_count;

	if(start_size == 1 || start_size == 0)
		return;
	else if(start_size == 2)
	{
		if(list->start_a->n > list->start_a->next->n)
			compress_cmds(list, sa);
		return;
	}
	else if(start_size == 3)
	{
		sort_small_stack(list, start_size);
		return;
	}
	make_pivot_go_next(list->start_a, start_size, &large_pivot, &small_pivot);
	ra_count = 0;
	pb_count = 0;
	rb_count = 0;
	while(start_size--)
	{
		if (list->start_a->n > large_pivot)
		{
			compress_cmds(list, ra);
			ra_count++;
		}
		else
		{
			compress_cmds(list, pb);
			pb_count++;
			if(list->start_b->n < small_pivot)
			{
				compress_cmds(list, rb);
				rb_count++;
			}
		}
	}
	if(issorted_a(list) == ERROR && ra_count > 3)
		sort_a_bottom(list, ra_count);
	else if(issorted_a(list) == ERROR)
		sort_small_a_bottom(list, ra_count);
	sort_b_top(list, pb_count - rb_count);
	sort_b_bottom(list, rb_count);
}
