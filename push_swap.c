/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:54:21 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/20 00:54:23 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list *list);

void	push_swap(t_list *list)
{
	while (ft_issorted(list) == ERROR)
	{
		if ()
			sa(list);
		else if ()
			sb(list);
		else if ()
			ss(list);
		else if ()
			pa(list);
		else if ()
			pb(list);
		else if ()
			ra(list);
		else if ()
			rb(list);
		else if ()
			rr(list);
		else if ()
			rra(list);
		else if ()
			rrb(list);
		else if ()
			rrr(list);
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
		if (now->n >= now->next - n)
			return (ERROR);
		now = now->next;
	}
	return (SUCCESS);
}
