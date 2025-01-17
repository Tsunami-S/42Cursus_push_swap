/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:35:59 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/06 15:04:42 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		check;
	t_list	list;

	list_init(&list);
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (char_check(argv[i]) == ERROR)
			return (error(), 0);
		i++;
	}
	if (argc == 2)
		check = init_stack_from_one(argv[1], &list);
	else
		check = init_stack_from_args(argc, argv, &list);
	if (check == ERROR)
		return (0);
	checker(&list);
	delete_stack(&list);
	return (0);
}
