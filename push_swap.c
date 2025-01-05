/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:40:14 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 18:20:17 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void make_stack_a_smaller(t_list *list, int start_size);
void sort_a_top(t_list *list, int start_size);
void sort_a_bottom(t_list *list, int start_size);
void rev_mid(t_list *list, int count);
void rev_small(t_list *list, int count);

void	push_swap(t_list *list)
{
	int	count;

	ash(list, init);
	count = stack_count(list->start_a);
	if (count <= 5)
		sort_small_stack(list, count);
	else
		make_stack_a_smaller(list, count);
	ash(list, none);
}

void make_stack_a_smaller(t_list *list, int start_size)
{
	int large_pivot;
	int small_pivot;
	int ra_count;
	int pb_count;
	int rb_count;

	make_two_pivot_go_next(list->start_a, start_size, &large_pivot, &small_pivot);
	ra_count = 0;
	pb_count = 0;
	rb_count = 0;
	while(start_size--)
	{
		if(list->start_a->n > large_pivot)
		{
			ash(list, ra);
			ra_count++;
		}
		else
		{
			pb_count++;
			ash(list, pb);
			if(list->start_b->n < small_pivot)
			{
				ash(list, rb);
				rb_count++;
			}
		}
	}
	if(issorted_a(list) == ERROR && ra_count > 4)
		make_stack_a_smaller(list, ra_count);
	else if(issorted_a(list) == ERROR)
		sort_small_stack(list, ra_count);
	rev_mid(list, pb_count - rb_count);
	rev_small(list, rb_count);
}

void rev_small(t_list *list, int count)
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
		three_small_sort(list, count);
		return;
	}
	else if(issorted_go_prev(list->end_b, count) == MINUS)
	{
		while(count--)
		{
			ash(list, rrb);
			ash(list, pa);
		}
		return;
	}
	else if(issorted_go_prev(list->end_b, count) == PLUS)
	{
		i = 0;
		while(i++ < count)
			ash(list, rrb);
		while(count--)
			ash(list, pa);
		return;
	}
	pa_count = 0;
	ra_count = 0;
	rrb_count = 0;
	make_two_pivot_go_prev(list->end_b, count, &large_pivot, &small_pivot);
	while(count--)
	{
		ash(list, rrb);
		rrb_count++;
		if(list->start_b->n > small_pivot)
		{
			ash(list, pa);
			pa_count++;
			if(list->start_a->n < large_pivot)
			{
				ash(list, ra);
				ra_count++;
			}
		}
	}
	sort_a_top(list, pa_count - ra_count);
	sort_a_bottom(list, ra_count);
	rev_mid(list, rrb_count - pa_count);
}

void rev_mid(t_list *list, int count)
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
		three_mid_sort(list, count);
		return;
	}
	else if(issorted_go_next(list->start_b, count) == MINUS)
	{
		while(count--)
			ash(list, pa);
		return;
	}
	ra_count = 0;
	pa_count = 0;
	rb_count = 0;
	make_two_pivot_go_next(list->start_b, count, &large_pivot, &small_pivot);
	while(count--)
	{
		if(list->start_b->n > small_pivot)
		{
			ash(list, pa);
			pa_count++;
			if(list->start_a->n < large_pivot)
			{
				ash(list, ra);
				ra_count++;
			}
		}
		else
		{
			ash(list, rb);
			rb_count++;
		}
	}
	sort_a_top(list, pa_count - ra_count);
	sort_a_bottom(list, ra_count);
	rev_small(list, rb_count);
}

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
		ash(list, rra);
		return;
	}
	else if(start_size == 2)
	{
		ash(list, rra);
		ash(list, rra);
		if(list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		return;
	}
	else if(start_size == 3)
	{
		sort_small_stack_bottom(list, start_size);
		return;
	}
	make_two_pivot_go_prev(list->end_a, start_size, &large_pivot, &small_pivot);
	rra_count = 0;
	pb_count = 0;
	rb_count = 0;
	while(start_size--)
	{
		ash(list, rra);
		rra_count++;
		if (list->start_a->n < large_pivot)
		{
			pb_count++;
			ash(list, pb);
			if(list->start_b->n < small_pivot)
			{
				ash(list, rb);
				rb_count++;
			}
		}
	}
	if(issorted_a(list) == ERROR && rra_count - pb_count > 3)
		sort_a_top(list, rra_count - pb_count);
	else if(issorted_a(list) == ERROR)
		sort_small_stack(list, rra_count - pb_count);
	rev_mid(list, pb_count - rb_count);
	rev_small(list, rb_count);
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
			ash(list, sa);
		return;
	}
	else if(start_size == 3)
	{
		sort_small_stack(list, start_size);
		return;
	}
	make_two_pivot_go_next(list->start_a, start_size, &large_pivot, &small_pivot);
	ra_count = 0;
	pb_count = 0;
	rb_count = 0;
	while(start_size--)
	{
		if (list->start_a->n > large_pivot)
		{
			ash(list, ra);
			ra_count++;
		}
		else
		{
			ash(list, pb);
			pb_count++;
			if(list->start_b->n < small_pivot)
			{
				ash(list, rb);
				rb_count++;
			}
		}
	}
	if(issorted_a(list) == ERROR && ra_count > 3)
		sort_a_bottom(list, ra_count);
	else if(issorted_a(list) == ERROR)
		sort_small_stack_bottom(list, ra_count);
	rev_mid(list, pb_count - rb_count);
	rev_small(list, rb_count);
}
