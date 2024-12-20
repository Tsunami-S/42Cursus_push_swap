/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:21 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/20 15:54:34 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_a(t_list *list);
static int	swap_b(t_list *list);

void	swap(t_list *list, t_act act)
{
	int	check_a;
	int	check_b;

	check_a = 0;
	check_b = 0;
	if (act == sa)
		check_a = swap_a(list);
	else if (act == sb)
		check_b = swap_b(list);
	else if (act == ss)
	{
		check_a = swap_a(list);
		check_b = swap_b(list);
	}
	if (check_a == SUCCESS && check_b == SUCCESS)
		write(1, "ss\n", 3);
	else if (check_a == SUCCESS)
		write(1, "sa\n", 3);
	else if (check_b == SUCCESS)
		write(1, "sb\n", 3);
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
