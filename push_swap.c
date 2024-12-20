/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:54:21 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/20 15:55:02 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_act	select_act(t_list *list);

/******************************debug******************************/
static int	is_sorted(t_list *list)
{
	t_stack	*now;

	if (list->start_b)
		return (ERROR);
	now = list->start_a;
	while (now->next)
	{
		if (now->n >= now->next->n)
			return (ERROR);
		now = now->next;
	}
	return (SUCCESS);
}
/******************************debug******************************/

void	push_swap(t_list *list)
{
	t_act	act;
	t_stack	*now;

	while (list->start_a)
	{
		act = select_act(list);
		if (act == sa || act == sb || act == ss)
			swap(list, act);
		else if (act == pa || act == pb)
			push(list, act);
		else if (act == ra || act == rb || act == rr)
			rotate(list, act);
		else if (act == rra || act == rrb || act == rrr)
			reverse(list, act);
	}
	while (list->start_b)
		push(list, pa);
	/******************************debug******************************/
	now = list->start_a;
	printf("<list>\n");
	if (list->start_a)
		printf("start_a: %d\n", list->start_a->n);
	if (list->end_a)
		printf("end_a: %d\n", list->end_a->n);
	if (list->start_b)
		printf("start_b: %d\n", list->start_b->n);
	if (list->end_b)
		printf("end_b: %d\n", list->end_b->n);
	printf("<stack_A>\n");
	while (now)
	{
		printf("%d\n", now->n);
		now = now->next;
	}
	if (is_sorted(list) == SUCCESS)
		printf("SUCCESS\n");
	/******************************debug******************************/
}

static t_act	select_act(t_list *list)
{
	t_stack	*st_a;
	t_stack	*st_b;
	t_stack	*ne_a;
	t_stack	*ne_b;
	t_stack	*en_a;
	t_stack	*en_b;

	st_a = list->start_a;
	st_b = list->start_b;
	if (st_a)
		ne_a = st_a->next;
	if (st_b)
		ne_b = st_b->next;
	en_a = list->end_a;
	en_b = list->end_b;
	if (st_a && st_b && ne_a && ne_b && st_a->n > ne_a->n && st_b->n < ne_b->n)
		return (ss);
	else if (st_a && ne_a && st_a->n > ne_a->n)
		return (sa);
	else if (st_b && ne_b && st_b->n < ne_b->n)
		return (sb);
	else if (st_b && en_b && st_b->n < en_b->n)
		return (rb);
	else if (st_a && en_a && st_a->n > en_a->n)
		return (rra);
	// else if(st_a && st_b && st_a->n < st_b->n)
	//	return (rb);
	// else if(en_b && st_a && en_b->n < st_a->n)
	//	return (rrb);
	return (pb);
}
