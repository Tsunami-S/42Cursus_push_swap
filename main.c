/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:01 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/31 09:16:09 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		check;
	t_list	list;

	list_init(&list);
	if (argc < 2)
		return (0);
	else if (argc == 2)
		check = init_stack_from_one(argv[1], &list);
	else
		check = init_stack_from_args(argc, argv, &list);
	if (check == ERROR)
		return (0);
	push_swap(&list, list.end_a, list.end_a);
	while(list.start_b)
	{
		t_stack *tmp = list.start_a;
		while(list.start_b)
			push(&list, pa);
		push_swap(&list, tmp, list.start_a);
	}
	/**********debug*********/
	t_stack *now = list.start_a;
	printf("<stack_A>\n");
	while(now)
	{
		printf("%d\n", now->n);
		now = now->next;
	}
	now = list.start_b;
	printf("<stack_B>\n");
	while(now)
	{
		printf("%d\n", now->n);
		now = now->next;
	}
	/**********debug*********/
	delete_stack(&list);
	return (0);
}
