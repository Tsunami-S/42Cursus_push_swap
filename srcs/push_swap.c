/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:40:14 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 23:47:19 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_list *list)
{
	int	count;

	compress_cmds(list, init);
	count = stack_count(list->start_a);
	if (count == 1 || issorted_go_next(list->start_a, count) == PLUS)
		return ;
	else if (count <= 5)
		sort_small_stack(list, count);
	else
		make_stack_a_smaller(list, count);
	compress_cmds(list, none);
}
