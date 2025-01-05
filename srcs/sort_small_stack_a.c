/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:48:26 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 22:23:08 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_three(t_list *list);
static void	sort_four(t_list *list);
static void	sort_five(t_list *list);
static void	merge(t_list *list, int len_a, int len_b);

void	sort_small_stack(t_list *list, int count)
{
	if (count == 1 || issorted_go_next(list->start_a, count) == PLUS)
		return ;
	if (count == 2)
		compress_cmds(list, sa);
	else if (count == 3)
		sort_three(list);
	else if (count == 4)
		sort_four(list);
	else if (count == 5)
		sort_five(list);
}

static void	sort_three(t_list *list)
{
	t_stack	*st_a;

	st_a = list->start_a;
	if (stack_count(list->start_a) == 3)
	{
		if (st_a->next->n < st_a->n && list->end_a->n < st_a->n)
			compress_cmds(list, ra);
		else if (st_a->n < st_a->next->n && list->end_a->n < st_a->next->n)
			compress_cmds(list, rra);
		if (list->start_a->n > list->start_a->next->n)
			compress_cmds(list, sa);
	}
	else
	{
		if (list->start_a->n > list->start_a->next->n)
			compress_cmds(list, sa);
		compress_cmds(list, pb);
		if (list->start_a->n > list->start_a->next->n)
			compress_cmds(list, sa);
		compress_cmds(list, pa);
		if (list->start_a->n > list->start_a->next->n)
			compress_cmds(list, sa);
	}
}

static void	sort_four(t_list *list)
{
	t_stack	*st_a;

	if (list->start_a->n > list->start_a->next->n)
		compress_cmds(list, sa);
	if (issorted_a(list) == SUCCESS)
		return ;
	st_a = list->start_a;
	if (st_a->n < st_a->next->next->n || st_a->n < st_a->next->next->next->n)
	{
		compress_cmds(list, pb);
		sort_three(list);
		compress_cmds(list, pa);
	}
	else
	{
		compress_cmds(list, ra);
		compress_cmds(list, sa);
		compress_cmds(list, pb);
		compress_cmds(list, rra);
		sort_three(list);
		compress_cmds(list, pa);
	}
	if (list->start_a->n > list->start_a->next->n)
		compress_cmds(list, sa);
}

static void	sort_five(t_list *list)
{
	t_stack	*st_a;

	if (list->start_a->n > list->start_a->next->n)
		compress_cmds(list, sa);
	if (issorted_a(list) == SUCCESS)
		return ;
	compress_cmds(list, pb);
	compress_cmds(list, pb);
	sort_three(list);
	st_a = list->start_a;
	if (st_a->n > list->start_b->n)
	{
		compress_cmds(list, pa);
		compress_cmds(list, pa);
		return ;
	}
	merge(list, 3, 2);
}

static void	merge(t_list *list, int len_a, int len_b)
{
	while (len_a && len_b)
	{
		if (len_a && list->end_a->n > list->start_b->n)
		{
			compress_cmds(list, rra);
			len_a--;
		}
		else if (len_b && list->end_a->n < list->start_b->n)
		{
			compress_cmds(list, pa);
			len_b--;
		}
	}
	while (!len_a && len_b)
	{
		compress_cmds(list, pa);
		len_b--;
	}
	while (!len_b && len_a)
	{
		compress_cmds(list, rra);
		len_a--;
	}
}
