/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:27:31 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/03 17:28:09 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*exec_pa_and_rb(t_list *list, t_stack *en_b, int medium)
{
	t_stack	*first_rb;
	t_stack	*now;

	first_rb = NULL;
	while (1)
	{
		now = list->start_b;
		if (list->start_b->n >= medium)
			ash(list, pa);
		else
		{
			if (!first_rb)
				first_rb = list->start_b;
			ash(list, rb);
		}
		if (now == en_b)
			break ;
	}
	return (first_rb);
}

t_stack	*exec_pa_and_rrb(t_list *list, t_stack *en_b, int medium)
{
	t_stack	*now;
	t_stack	*first_rrb;

	first_rrb = NULL;
	while (1)
	{
		now = list->end_b;
		if (list->start_b != list->end_b)
			ash(list, rrb);
		if (list->start_b->n >= medium)
			ash(list, pa);
		else if (!first_rrb)
			first_rrb = list->start_b;
		if (now == en_b)
			break ;
	}
	return (first_rrb);
}

t_stack	*exec_pb_and_ra(t_list *list, t_stack *en_b, int medium)
{
	t_stack	*first_pb;
	t_stack	*now;

	first_pb = NULL;
	while (1)
	{
		now = list->start_a;
		if (list->start_a->n < medium)
		{
			ash(list, pb);
			if (!first_pb)
				first_pb = list->start_b;
		}
		else if (now != en_b)
			ash(list, ra);
		if (now == en_b)
			break ;
	}
	return (first_pb);
}

t_stack	*exec_pb_and_rra(t_list *list, t_stack *en_a, int medium)
{
	t_stack	*first_pb;

	first_pb = NULL;
	while (list->end_a != en_a)
	{
		ash(list, rra);
		if (list->start_a->n < medium)
		{
			ash(list, pb);
			if (!first_pb)
				first_pb = list->start_b;
		}
	}
	return (first_pb);
}
