/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_back_to_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:12:16 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 22:42:36 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_small_a_bottom(t_list *list, int count)
{
	compress_cmds(list, rra);
	if (count == 2)
		compress_cmds(list, rra);
	else if (count == 3)
	{
		if (list->end_a->prev->n > list->end_a->n
			&& list->end_a->prev->n > list->start_a->n)
		{
			compress_cmds(list, pb);
			consecutive_cmds(list, rra, 2);
			compress_cmds(list, sa);
			compress_cmds(list, pa);
		}
		else
		{
			compress_cmds(list, rra);
			if (list->start_a->n > list->start_a->next->n)
				compress_cmds(list, sa);
			compress_cmds(list, rra);
		}
	}
	if (list->start_a->n > list->start_a->next->n)
		compress_cmds(list, sa);
}

void	sort_small_b_top(t_list *list, int count)
{
	if (count == 1)
		compress_cmds(list, pa);
	else if (count == 2)
	{
		consecutive_cmds(list, pa, 2);
		if (list->start_a->n > list->start_a->next->n)
			compress_cmds(list, sa);
	}
	else
	{
		if (list->start_b->n < list->start_b->next->n)
			compress_cmds(list, sb);
		compress_cmds(list, pa);
		if (list->start_b->n < list->start_b->next->n)
			compress_cmds(list, sb);
		compress_cmds(list, pa);
		if (list->start_a->n > list->start_a->next->n)
			compress_cmds(list, sa);
		compress_cmds(list, pa);
	}
}

void	sort_small_b_bottom(t_list *list, int count)
{
	compress_cmds(list, rrb);
	if (count == 1)
		compress_cmds(list, pa);
	else if (count == 2)
	{
		compress_cmds(list, rrb);
		consecutive_cmds(list, pa, 2);
		if (list->start_a->n > list->start_a->next->n)
			compress_cmds(list, sa);
	}
	else
	{
		consecutive_cmds(list, rrb, 2);
		sort_small_b_top(list, 3);
	}
}
