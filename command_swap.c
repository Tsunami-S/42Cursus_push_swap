/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:21 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/03 15:56:00 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_a(t_list *list);
static int	swap_b(t_list *list);

void	swap(t_list *list, t_act act)
{
	if (act == sa)
		swap_a(list);
	else if (act == sb)
		swap_b(list);
	else if (act == ss)
	{
		swap_a(list);
		swap_b(list);
	}
}

static int	swap_a(t_list *list)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = list->start_a;
	if (!node1)
		return (ERROR);
	node2 = node1->next;
	if (!node2)
		return (ERROR);
	list->start_a = node2;
	if (list->end_a == node2)
		list->end_a = node1;
	node1->next = node2->next;
	if (node1->next)
		node1->next->prev = node1;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	return (SUCCESS);
}

static int	swap_b(t_list *list)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = list->start_b;
	if (!node1)
		return (ERROR);
	node2 = node1->next;
	if (!node2)
		return (ERROR);
	list->start_b = node2;
	if (list->end_b == node2)
		list->end_b = node1;
	node1->next = node2->next;
	if (node1->next)
		node1->next->prev = node1;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	return (SUCCESS);
}
