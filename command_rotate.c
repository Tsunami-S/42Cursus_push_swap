/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:17 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/02 21:11:37 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_a(t_list *list);
static int	rotate_b(t_list *list);

void	rotate(t_list *list, t_act act)
{
	if (act == ra)
		rotate_a(list);
	else if (act == rb)
		rotate_b(list);
	else if (act == rr)
	{
		rotate_a(list);
		rotate_b(list);
	}
//	if (check_a == SUCCESS && check_b == SUCCESS)
//		write(1, "rr\n", 3);
//	else if (check_a == SUCCESS)
//		write(1, "ra\n", 3);
//	else if (check_b == SUCCESS)
//		write(1, "rb\n", 3);
}

static int	rotate_a(t_list *list)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = list->start_a;
	node2 = list->end_a;
	if (!node1 || !node2 || node1 == node2)
		return (ERROR);
	list->start_a = node1->next;
	//if (node1->next)
	node1->next->prev = NULL;
	node2->next = node1;
	node1->next = NULL;
//	if (node1)
	node1->prev = node2;
	list->end_a = node1;
	return (SUCCESS);
}

static int	rotate_b(t_list *list)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = list->start_b;
	node2 = list->end_b;
	if (!node1 || !node2 || node1 == node2)
		return (ERROR);
	list->start_b = node1->next;
	//if (node1->next)
	node1->next->prev = NULL;
	node2->next = node1;
	node1->next = NULL;
	//if (node1)
	node1->prev = node2;
	list->end_b = node1;
	return (SUCCESS);
}
