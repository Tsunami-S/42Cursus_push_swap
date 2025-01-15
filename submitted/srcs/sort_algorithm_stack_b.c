/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_stack_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:26:04 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/06 00:27:13 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	pa_sorted_stacks(t_list *list, int count);
static void	exec_sort_b_top(t_list *list, int size, int *pa_count,
				int *ra_count);
static void	exec_sort_b_btm(t_list *list, int size, int *pa_count,
				int *ra_count);

void	sort_b_top(t_list *list, int count)
{
	int	ra_count;
	int	pa_count;
	int	rb_count;

	if (count == 0)
		return ;
	if (count <= 3)
	{
		sort_small_b_top(list, count);
		return ;
	}
	else if (issorted_go_next(list->start_b, count) == MINUS)
	{
		consecutive_cmds(list, pa, count);
		return ;
	}
	ra_count = 0;
	pa_count = 0;
	exec_sort_b_top(list, count, &pa_count, &ra_count);
	rb_count = count - pa_count;
	sort_a_top(list, pa_count - ra_count);
	sort_a_bottom(list, ra_count);
	sort_b_bottom(list, rb_count);
}

void	sort_b_bottom(t_list *list, int count)
{
	int	ra_count;
	int	pa_count;
	int	rrb_count;

	if (count == 0)
		return ;
	if (count <= 3)
	{
		sort_small_b_bottom(list, count);
		return ;
	}
	else if (pa_sorted_stacks(list, count) == SUCCESS)
		return ;
	pa_count = 0;
	ra_count = 0;
	exec_sort_b_btm(list, count, &pa_count, &ra_count);
	rrb_count = count - pa_count;
	sort_a_top(list, pa_count - ra_count);
	sort_a_bottom(list, ra_count);
	sort_b_top(list, rrb_count);
}

static int	pa_sorted_stacks(t_list *list, int count)
{
	int	check;

	check = issorted_go_prev(list->end_b, count);
	if (check == PLUS)
	{
		consecutive_cmds(list, rrb, count);
		consecutive_cmds(list, pa, count);
		return (SUCCESS);
	}
	else if (check == MINUS)
	{
		while (count--)
		{
			compress_cmds(list, rrb);
			compress_cmds(list, pa);
		}
		return (SUCCESS);
	}
	return (ERROR);
}

static void	exec_sort_b_top(t_list *list, int size, int *pa_count,
		int *ra_count)
{
	int	large_pivot;
	int	small_pivot;

	make_pivot_go_next(list->start_b, size, &large_pivot, &small_pivot);
	while (size--)
	{
		if (list->start_b->n > small_pivot)
		{
			compress_cmds(list, pa);
			(*pa_count)++;
			if (list->start_a->n < large_pivot)
			{
				compress_cmds(list, ra);
				(*ra_count)++;
			}
		}
		else
			compress_cmds(list, rb);
	}
}

static void	exec_sort_b_btm(t_list *list, int size, int *pa_count,
		int *ra_count)
{
	int	large_pivot;
	int	small_pivot;

	make_pivot_go_prev(list->end_b, size, &large_pivot, &small_pivot);
	while (size--)
	{
		compress_cmds(list, rrb);
		if (list->start_b->n > small_pivot)
		{
			compress_cmds(list, pa);
			(*pa_count)++;
			if (list->start_a->n < large_pivot)
			{
				compress_cmds(list, ra);
				(*ra_count)++;
			}
		}
	}
}
