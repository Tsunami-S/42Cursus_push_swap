/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:16:39 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 22:30:58 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	make_pivot_go_next(t_stack *start, int size, int *large, int *small)
{
	t_stack		*now;
	long long	total;
	int			count;

	total = 0;
	count = 0;
	now = start;
	while (count++ < size)
	{
		total += now->n;
		now = now->next;
	}
	*large = total / size;
	count = 0;
	now = start;
	while (size--)
	{
		if (now->n > *large)
			total -= now->n;
		else
			count++;
		now = now->next;
	}
	*small = total / count;
}

void	make_pivot_go_prev(t_stack *start, int size, int *large, int *small)
{
	t_stack		*now;
	long long	total;
	int			count;

	total = 0;
	count = 0;
	now = start;
	while (count++ < size)
	{
		total += now->n;
		now = now->prev;
	}
	*large = total / size;
	count = 0;
	now = start;
	while (size--)
	{
		if (now->n > *large)
			total -= now->n;
		else
			count++;
		now = now->prev;
	}
	*small = total / count;
}
