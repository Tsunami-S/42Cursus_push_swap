/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:21 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/20 00:18:22 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sa(t_list *list);
static int	sb(t_list *list);

void	swap(t_list *list, char c)
{
	int	check_a;
	int	check_b;

	check_a = 0;
	check_b = 0;
	if (c == 'a')
		check_a = sa(list);
	else if (c == 'b')
		check_b = sb(list);
	else if (c == 's')
	{
		check_a = sa(list);
		check_b = sb(list);
	}
	if (check_a == SUCCESS && check_b == SUCCESS)
		write(1, "ss\n", 3);
	else if (check_a == SUCCESS)
		write(1, "sa\n", 3);
	else if (check_b == SUCCESS)
		write(1, "sb\n", 3);
}

static int	sa(t_list *list)
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
	node1->next = node2->next;
	node1->next->prev = node1;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	return (SUCCESS);
}

static int	sb(t_list *list)
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
	node1->next = node2->next;
	node1->next->prev = node1;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	return (SUCCESS);
}
