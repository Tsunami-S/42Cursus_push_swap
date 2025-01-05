#include "../inc/push_swap.h"

void sort_b_bottom(t_list *list, int count)
{
	int i;
	int large_pivot;
	int small_pivot;
	int ra_count;
	int pa_count;
	int rrb_count;

	if(count == 0)
		return;
	if(count <= 3)
	{
		sort_small_b_bottom(list, count);
		return;
	}
	else if(issorted_go_prev(list->end_b, count) == MINUS)
	{
		while(count--)
		{
			compress_cmds(list, rrb);
			compress_cmds(list, pa);
		}
		return;
	}
	else if(issorted_go_prev(list->end_b, count) == PLUS)
	{
		i = 0;
		while(i++ < count)
			compress_cmds(list, rrb);
		while(count--)
			compress_cmds(list, pa);
		return;
	}
	pa_count = 0;
	ra_count = 0;
	rrb_count = 0;
	make_pivot_go_prev(list->end_b, count, &large_pivot, &small_pivot);
	while(count--)
	{
		compress_cmds(list, rrb);
		rrb_count++;
		if(list->start_b->n > small_pivot)
		{
			compress_cmds(list, pa);
			pa_count++;
			if(list->start_a->n < large_pivot)
			{
				compress_cmds(list, ra);
				ra_count++;
			}
		}
	}
	sort_a_top(list, pa_count - ra_count);
	sort_a_bottom(list, ra_count);
	sort_b_top(list, rrb_count - pa_count);
}

void sort_b_top(t_list *list, int count)
{
	int large_pivot;
	int small_pivot;
	int ra_count;
	int pa_count;
	int rb_count;

	if(count == 0)
		return;
	if(count <= 3)
	{
		sort_small_b_top(list, count);
		return;
	}
	else if(issorted_go_next(list->start_b, count) == MINUS)
	{
		while(count--)
			compress_cmds(list, pa);
		return;
	}
	ra_count = 0;
	pa_count = 0;
	rb_count = 0;
	make_pivot_go_next(list->start_b, count, &large_pivot, &small_pivot);
	while(count--)
	{
		if(list->start_b->n > small_pivot)
		{
			compress_cmds(list, pa);
			pa_count++;
			if(list->start_a->n < large_pivot)
			{
				compress_cmds(list, ra);
				ra_count++;
			}
		}
		else
		{
			compress_cmds(list, rb);
			rb_count++;
		}
	}
	sort_a_top(list, pa_count - ra_count);
	sort_a_bottom(list, ra_count);
	sort_b_bottom(list, rb_count);
}

