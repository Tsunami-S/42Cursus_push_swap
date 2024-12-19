/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:13 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/20 00:18:14 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rra(t_list *list);
static int	rrb(t_list *list);

void	reverse(t_list *list, char c)
{
	int	check_a;
	int	check_b;

	check_a = 0;
	check_b = 0;
	if (c == 'a')
		check_a = rra(list);
	else if (c == 'b')
		check_b = rrb(list);
	else if (c == 'r')
	{
		check_a = rra(list);
		check_b = rrb(list);
	}
	if (check_a == SUCCESS && check_b == SUCCESS)
		write(1, "rrr\n", 4);
	else if (check_a == SUCCESS)
		write(1, "rra\n", 4);
	else if (check_b == SUCCESS)
		write(1, "rrr\n", 4);
}

static int	rra(t_list *list)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = list->start_a;
	node2 = list->end_a;
	if (node1 == node2)
		return (ERROR);
	list->start_a = node2;
	list->end_a = node2->prev;
	node2->prev->next = NULL;
	node2->next = node1;
	node2->prev = NULL;
	node1->prev = node2;
	return (SUCCESS);
}

static int	rrb(t_list *list)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = list->start_b;
	node2 = list->end_b;
	if (node1 == node2)
		return (ERROR);
	list->start_b = node2;
	list->end_b = node2->prev;
	node2->prev->next = NULL;
	node2->next = node1;
	node2->prev = NULL;
	node1->prev = node2;
	return (SUCCESS);
}
