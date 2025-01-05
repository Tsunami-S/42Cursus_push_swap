/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:16:39 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 13:14:07 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge(t_list *list, int len_a, int len_b)
{
	while (len_a && len_b)
	{
		if (len_a && list->end_a->n > list->start_b->n)
		{
			ash(list, rra);
			len_a--;
		}
		else if (len_b && list->end_a->n < list->start_b->n)
		{
			ash(list, pa);
			len_b--;
		}
	}
	while (!len_a && len_b)
	{
		ash(list, pa);
		len_b--;
	}
	while (!len_b && len_a)
	{
		ash(list, rra);
		len_a--;
	}
}


void	reverse_to_start_a(t_list *list, int count)
{
	if (!list->sorted_num)
		return ;
	while (list->end_a != list->sorted_ena)
		ash(list, rra);
	(void)count;
}

int	make_medium(t_stack *start, t_stack *end)
{
	long long	total;
	int			i;

	total = 0;
	i = 1;
	while (start != end)
	{
		total += start->n;
		start = start->next;
		i++;
	}
	total += start->n;
	return (total / i);
}

int	stack_count(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
