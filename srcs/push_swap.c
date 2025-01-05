/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:40:14 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 23:12:12 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_stack_a(t_list *list, int size, int *pb_count, int *rb_count);

void	push_swap(t_list *list)
{
	int	count;

	compress_cmds(list, init);
	count = stack_count(list->start_a);
	if (count == 1 || issorted_go_next(list->start_a, count) == PLUS)
		return ;
	else if (count <= 5)
		sort_small_stack(list, count);
	else
		make_stack_a_smaller(list, count);
	compress_cmds(list, none);
}

void	make_stack_a_smaller(t_list *list, int start_size)
{
	int	ra_count;
	int	pb_count;
	int	rb_count;

	pb_count = 0;
	rb_count = 0;
	sort_stack_a(list, start_size, &pb_count, &rb_count);
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

static void	sort_stack_a(t_list *list, int size, int *pb_count, int *rb_count)
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
