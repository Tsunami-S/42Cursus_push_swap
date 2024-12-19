/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:54:21 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/20 01:36:15 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_sorted(t_list *list);
static t_act	select_act(t_list *list);

void	push_swap(t_list *list)
{
	t_act	act;

	while (is_sorted(list) == ERROR)
	{
		act = select_act(list);
		if (act == sa || act == sb || act == ss)
			swap(list, act);
		else if (act == pa || act == pb)
			push(list, act);
		else if (act == ra || act == rb || act == rr)
			rotate(list, act);
		else if (act == rra || act == rrb || act == rrr)
			reverse(list, act);
	}
}

static int	is_sorted(t_list *list)
{
	t_stack	*now;

	if (list->start_b)
		return (ERROR);
	now = list->start_a;
	while (now->next)
	{
		if (now->n >= now->next->n)
			return (ERROR);
		now = now->next;
	}
	return (SUCCESS);
}

static t_act	select_act(t_list *list)
{
}
