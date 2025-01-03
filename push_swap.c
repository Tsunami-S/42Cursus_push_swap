/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:40:14 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/04 00:25:48 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_small_stacks(t_list *list, int count);

void	pa_small_stacks(t_list *list, int count)
{
	if (count == 1)
		ash(list, pa);
	else if (count == 2)
	{
		ash(list, pa);
		ash(list, pa);
		if (list->start_a->n > list->start_a->next->n)
			ash(list, sa);
	}
	else if (count == 3)
	{
		if (list->start_b->n < list->start_b->next->n)
			ash(list, sb);
		ash(list, pa);
		if (list->start_b->n < list->start_b->next->n)
			ash(list, sb);
		ash(list, pa);
		if (list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		ash(list, pa);
	}
	list->sorted_sta = list->start_a;
	list->sorted_ena = list->end_a;
	list->sorted_num = stack_count(list->start_a);
}

void	push_swap(t_list *list)
{
	int	count;

	ash(list, init);
	count = stack_count(list->start_a);
	if (count <= 4)
	{
		if (issorted_a(list) == ERROR)
			sort_small_stack(list, count);
		ash(list, none);
		return ;
	}
	pb_and_ra(list, list->end_a, make_medium(list->start_a, list->end_a));
	ash(list, none);
}

void	pa_and_rb(t_list *list, t_stack *en_b, int medium)
{
	int		count;
	t_stack	*first_rb;

	if (list->start_b == en_b)
	{
		pa_small_stacks(list, 1);
		return ;
	}
	else if (list->start_b->next == en_b)
	{
		pa_small_stacks(list, 2);
		return ;
	}
	else if (list->start_b->next->next == en_b)
	{
		pa_small_stacks(list, 3);
		return ;
	}
	first_rb = exec_pa_and_rb(list, en_b, medium);
	count = stack_count(list->start_a) - list->sorted_num;
	if (issorted_a(list) == ERROR && count > 4)
		pb_and_ra(list, list->sorted_sta, make_medium(list->start_a,
				list->sorted_sta->prev));
	else if (issorted_a(list) == ERROR && count > 0)
		sort_small_stack(list, count);
	if (first_rb)
		pa_and_rrb(list, first_rb, make_medium(first_rb, list->end_b));
}

void	pa_and_rrb(t_list *list, t_stack *en_b, int medium)
{
	int		count;
	t_stack	*first_rrb;

	if (list->end_b == en_b)
	{
		ash(list, rrb);
		pa_small_stacks(list, 1);
		return ;
	}
	else if (list->end_b->prev == en_b)
	{
		ash(list, rrb);
		ash(list, rrb);
		pa_small_stacks(list, 2);
		return ;
	}
	else if (list->end_b->prev->prev == en_b)
	{
		ash(list, rrb);
		ash(list, rrb);
		ash(list, rrb);
		pa_small_stacks(list, 3);
		return ;
	}
	first_rrb = exec_pa_and_rrb(list, en_b, medium);
	count = stack_count(list->start_a) - list->sorted_num;
	if (issorted_a(list) == ERROR && count > 4)
		pb_and_ra(list, list->sorted_sta, make_medium(list->start_a,
				list->sorted_sta->prev));
	else if (issorted_a(list) == ERROR && count > 0)
		sort_small_stack(list, count);
	if (first_rrb)
		pa_and_rb(list, first_rrb, make_medium(list->start_b, first_rrb));
}

void	pb_and_ra(t_list *list, t_stack *en_a, int medium)
{
	t_stack	*first_pb;
	int		count;
	t_stack	*now;

	now = list->start_a;
	count = 1;
	while (now != en_a)
	{
		now = now->next;
		count++;
	}
	if (count < 4)
	{
		sort_small_stack(list, count);
		return ;
	}
	first_pb = exec_pb_and_ra(list, en_a, medium);
	count = stack_count(list->start_a) - list->sorted_num;
	if (issorted_a(list) == ERROR && count > 4 && !list->sorted_num)
		pb_and_ra(list, list->end_a, make_medium(list->start_a, list->end_a));
	else if (issorted_a(list) == ERROR && count > 4)
		pb_and_rra(list, list->sorted_ena, make_medium(list->sorted_ena->next,
				list->end_a));
	else if (issorted_a(list) == ERROR && count > 0)
		sort_small_stack(list, count);
	if (first_pb)
		pa_and_rb(list, first_pb, make_medium(list->start_b, first_pb));
}

void	pb_and_rra(t_list *list, t_stack *en_a, int medium)
{
	t_stack	*first_pb;
	int		count;
	int		flag;

	if (list->end_a == en_a)
	{
		ash(list, rra);
		issorted_a(list);
		return ;
	}
	else if (list->end_a->prev == en_a)
	{
		ash(list, rra);
		ash(list, rra);
		if (list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		issorted_a(list);
		return ;
	}
	else if (list->end_a->prev->prev == en_a)
	{
		ash(list, rra);
		ash(list, rra);
		if (list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		flag = 0;
		if (list->start_a->next->n < list->end_a->n)
		{
			flag = 1;
			ash(list, pb);
		}
		ash(list, rra);
		if (list->start_a->n > list->start_a->next->n)
			ash(list, sa);
		if (flag)
			ash(list, pa);
		issorted_a(list);
		return ;
	}
	first_pb = exec_pb_and_rra(list, en_a, medium);
	count = stack_count(list->start_a) - list->sorted_num;
	if (issorted_a(list) == ERROR && count > 4)
		pb_and_ra(list, list->sorted_sta, make_medium(list->start_a,
				list->sorted_sta->prev));
	else if (issorted_a(list) == ERROR && count > 0)
		sort_small_stack(list, count);
	if (first_pb)
		pa_and_rb(list, first_pb, make_medium(list->start_b, first_pb));
}
