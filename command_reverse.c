/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:13 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/20 01:15:43 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_a(t_list *list);
static int	reverse_b(t_list *list);

void	reverse(t_list *list, t_act act)
{
	int	check_a;
	int	check_b;

	check_a = 0;
	check_b = 0;
	if (act == rra)
		check_a = reverse_a(list);
	else if (act == rrb)
		check_b = reverse_b(list);
	else if (act == rrr)
	{
		check_a = reverse_a(list);
		check_b = reverse_b(list);
	}
	if (check_a == SUCCESS && check_b == SUCCESS)
		write(1, "rrr\n", 4);
	else if (check_a == SUCCESS)
		write(1, "rra\n", 4);
	else if (check_b == SUCCESS)
		write(1, "rrr\n", 4);
}

static int	reverse_a(t_list *list)
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

static int	reverse_b(t_list *list)
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
