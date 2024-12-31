/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:35 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/31 09:22:46 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_init(t_list *list)
{
	list->start_a = NULL;
	list->start_b = NULL;
	list->end_a = NULL;
	list->end_b = NULL;
	list->sorted_sta = NULL;
	list->sorted_ena = NULL;
	list->sorted_num = 0;
}

void	delete_stack(t_list *list)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tmp;

	stack_a = list->start_a;
	stack_b = list->start_b;
	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	while (stack_b)
	{
		tmp = stack_b;
		stack_b = stack_b->next;
		free(tmp);
	}
}

void	error(void)
{
	write(2, "Error\n", 6);
}
