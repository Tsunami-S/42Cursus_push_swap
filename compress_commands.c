/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:01:39 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 19:23:01 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ash(t_list *list, t_act act);
void	write_command(t_act act);
void	select_act(t_list *list, t_act act);

void	ash(t_list *list, t_act act)
{
	static t_act	prev;
//	static int		i;

	if (act == init)
	{
//		i = 0;
		prev = none;
		return ;
	}
	select_act(list, act);
//	if ((prev == pa && act == pa) || (prev == pb && act == pb) || (prev == ra
//			&& act == ra) || (prev == rb && act == rb) || (prev == rra
//			&& act == rra) || (prev == rrb && act == rrb))
//	{
//		if (!i)
//			i = 2;
//		else
//			i++;
//		return ;
//	}
//	else if (i && ((prev == pa && act == pb) || (prev == pb && act == pa)
//			|| (prev == ra && act == rra) || (prev == rb && act == rrb)
//			|| (prev == rra && act == ra) || (prev == rrb && act == rb)))
//	{
//		i--;
//		if (!i)
//			prev = none;
//		return ;
//	}
//	else if (i > 0)
//	{
//		while (i-- > 0)
//			write_command(prev);
//		i = 0;
//		prev = act;
//		return ;
//	}
	if ((prev == sa && act == sb) || (prev == sb && act == sa))
		write_command(ss);
	else if ((prev == ra && act == rb) || (prev == rb && act == ra))
		write_command(rr);
	else if ((prev == rra && act == rrb) || (prev == rrb && act == rra))
		write_command(rrr);
	else if (!((prev == pa && act == pb) || (prev == pb && act == pa)
			|| (prev == ra && act == rra) || (prev == rb && act == rrb)
			|| (prev == rra && act == ra) || (prev == rrb && act == rb)))
	{
		write_command(prev);
		prev = act;
		return ;
	}
	prev = none;
}

void	select_act(t_list *list, t_act act)
{
	if (act == sa || act == sb || act == ss)
		swap(list, act);
	else if (act == pa || act == pb)
		push(list, act);
	else if (act == ra || act == rb || act == rr)
		rotate(list, act);
	else if (act == rra || act == rrb || act == rrr)
		reverse(list, act);
}

void	write_command(t_act act)
{
	if (act == sa)
		write(1, "sa\n", 3);
	else if (act == sb)
		write(1, "sb\n", 3);
	else if (act == ss)
		write(1, "ss\n", 3);
	else if (act == pa)
		write(1, "pa\n", 3);
	else if (act == pb)
		write(1, "pb\n", 3);
	else if (act == ra)
		write(1, "ra\n", 3);
	else if (act == rb)
		write(1, "rb\n", 3);
	else if (act == rr)
		write(1, "rr\n", 3);
	else if (act == rra)
		write(1, "rra\n", 4);
	else if (act == rrb)
		write(1, "rrb\n", 4);
	else if (act == rrr)
		write(1, "rrr\n", 4);
}
