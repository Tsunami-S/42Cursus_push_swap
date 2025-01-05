/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:48:26 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 18:06:36 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list *list);
void	sort_four(t_list *list);
void	sort_five(t_list *list);
void	sort_six(t_list *list);

void	sort_small_stack(t_list *list, int count)
{
//	reverse_to_start_a(list, count);
	if (count == 1 || issorted_go_next(list->start_a, count) == PLUS)
		return ;
	if (count == 2)
		ash(list, sa);
	else if (count == 3)
		sort_three(list);
	else if (count == 4)
		sort_four(list);
	else if (count == 5)
		sort_five(list);
	else if (count == 6)
		sort_six(list);
	list->sorted_sta = list->start_a;
	list->sorted_ena = list->end_a;
	list->sorted_num = stack_count(list->start_a);
}

void	sort_three(t_list *list)
{
	t_stack	*st_a;

	st_a = list->start_a;
	if (stack_count(list->start_a) == 3)
	{
		if (st_a->next->n < st_a->n && list->end_a->n < st_a->n)
			ash(list, ra);
		else if (st_a->n < st_a->next->n && list->end_a->n < st_a->next->n)
			ash(list, rra);
		if (list->start_a->n > list->start_a->next->n)
			ash(list, sa);
	}
	else
	{
		if (list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		ash(list, pb);
		if (list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		ash(list, pa);
		if (list->start_a->n > list->start_a->next->n)
			ash(list, sa);
	}
}

void	sort_four(t_list *list)
{
	t_stack	*st_a;

	if (list->start_a->n > list->start_a->next->n)
		ash(list, sa);
	if (issorted_a(list) == SUCCESS)
		return ;
	st_a = list->start_a;
	if (st_a->n < st_a->next->next->n || st_a->n < st_a->next->next->next->n)
	{
		ash(list, pb);
		sort_three(list);
		ash(list, pa);
	}
	else
	{
		ash(list, ra);
		ash(list, sa);
		ash(list, pb);
		ash(list, rra);
		sort_three(list);
		ash(list, pa);
	}
	if (list->start_a->n > list->start_a->next->n)
		ash(list, sa);
}

void	sort_five(t_list *list)
{
	t_stack	*st_a;

	if (list->start_a->n > list->start_a->next->n)
		ash(list, sa);
	if (issorted_a(list) == SUCCESS)
		return ;
	ash(list, pb);
	ash(list, pb);
	sort_three(list);
	st_a = list->start_a;
	if (st_a->n > list->start_b->n)
	{
		ash(list, pa);
		ash(list, pa);
		return ;
	}
	else if (list->sorted_num)
	{
		ash(list, ra);
		ash(list, ra);
		ash(list, ra);
	}
	merge(list, 3, 2);
}

void	sort_six(t_list *list)
{
	sort_three(list);
	if (issorted_a(list) == SUCCESS)
		return ;
	ash(list, pb);
	ash(list, pb);
	ash(list, pb);
	sort_three(list);
	if (stack_count(list->start_a) != 3)
	{
		ash(list, ra);
		ash(list, ra);
		ash(list, ra);
	}
	merge(list, 3, 3);
}
