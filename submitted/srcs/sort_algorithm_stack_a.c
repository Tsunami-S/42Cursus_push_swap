/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_stack_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:59:51 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/06 00:03:44 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	exec_sort_a_top(t_list *list, int size, int *pb_count,
				int *rb_count);
static void	exec_sort_a_btm(t_list *list, int size, int *pb_count,
				int *rb_count);

void	make_stack_a_smaller(t_list *list, int start_size)
{
	int	ra_count;
	int	pb_count;
	int	rb_count;

	pb_count = 0;
	rb_count = 0;
	exec_sort_a_top(list, start_size, &pb_count, &rb_count);
	ra_count = start_size - pb_count;
	if (issorted_a(list) == ERROR)
	{
		if (ra_count > 4)
			make_stack_a_smaller(list, ra_count);
		else
			sort_small_stack(list, ra_count);
	}
	sort_b_top(list, pb_count - rb_count);
	sort_b_bottom(list, rb_count);
}

void	sort_a_top(t_list *list, int start_size)
{
	int	ra_count;
	int	pb_count;
	int	rb_count;

	if (start_size == 0)
		return ;
	else if (start_size <= 3)
	{
		sort_small_stack(list, start_size);
		return ;
	}
	pb_count = 0;
	rb_count = 0;
	exec_sort_a_top(list, start_size, &pb_count, &rb_count);
	ra_count = start_size - pb_count;
	if (issorted_a(list) == ERROR)
	{
		if (ra_count > 3)
			sort_a_bottom(list, ra_count);
		else
			sort_small_a_bottom(list, ra_count);
	}
	sort_b_top(list, pb_count - rb_count);
	sort_b_bottom(list, rb_count);
}

void	sort_a_bottom(t_list *list, int start_size)
{
	int	rra_count;
	int	pb_count;
	int	rb_count;

	if (start_size == 0)
		return ;
	if (start_size <= 3)
	{
		sort_small_a_bottom(list, start_size);
		return ;
	}
	pb_count = 0;
	rb_count = 0;
	exec_sort_a_btm(list, start_size, &pb_count, &rb_count);
	rra_count = start_size - pb_count;
	if (issorted_a(list) == ERROR)
	{
		if (rra_count > 3)
			sort_a_top(list, rra_count);
		else
			sort_small_stack(list, rra_count);
	}
	sort_b_top(list, pb_count - rb_count);
	sort_b_bottom(list, rb_count);
}

static void	exec_sort_a_top(t_list *list, int size, int *pb_count,
		int *rb_count)
{
	int	large_pivot;
	int	small_pivot;

	make_pivot_go_next(list->start_a, size, &large_pivot, &small_pivot);
	while (size--)
	{
		if (list->start_a->n > large_pivot)
			compress_cmds(list, ra);
		else
		{
			(*pb_count)++;
			compress_cmds(list, pb);
			if (list->start_b->n < small_pivot)
			{
				compress_cmds(list, rb);
				(*rb_count)++;
			}
		}
	}
}

static void	exec_sort_a_btm(t_list *list, int size, int *pb_count,
		int *rb_count)
{
	int	large_pivot;
	int	small_pivot;

	make_pivot_go_prev(list->end_a, size, &large_pivot, &small_pivot);
	while (size--)
	{
		compress_cmds(list, rra);
		if (list->start_a->n < large_pivot)
		{
			(*pb_count)++;
			compress_cmds(list, pb);
			if (list->start_b->n < small_pivot)
			{
				compress_cmds(list, rb);
				(*rb_count)++;
			}
		}
	}
}
