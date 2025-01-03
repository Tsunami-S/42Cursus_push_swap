/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:40:14 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/03 19:47:01 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack	*first_rb;
	int		count;

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
