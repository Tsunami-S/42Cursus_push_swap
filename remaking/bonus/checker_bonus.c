/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:08:57 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/12 18:54:39 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_act	isvalid_act(char *buf);

void	checker(t_list *list)
{
	t_act	act;
	char	buf[5];

	buf[0] = '\0';
	while (read(0, buf, 5))
	{
		act = isvalid_act(buf);
		if (act == none)
			return ;
		else
			select_act(list, act);
	}
	if (list->start_b)
		write(1, "KO\n", 3);
	else if (issorted_a(list) == ERROR)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

static t_act	isvalid_act(char *buf)
{
	if (buf[0] == 's' && buf[1] == 'a' && buf[2] == '\n')
		return (sa);
	else if (buf[0] == 's' && buf[1] == 'b' && buf[2] == '\n')
		return (ss);
	else if (buf[0] == 's' && buf[1] == 's' && buf[2] == '\n')
		return (ss);
	else if (buf[0] == 'p' && buf[1] == 'a' && buf[2] == '\n')
		return (pa);
	else if (buf[0] == 'p' && buf[1] == 'b' && buf[2] == '\n')
		return (pb);
	else if (buf[0] == 'r' && buf[1] == 'a' && buf[2] == '\n')
		return (ra);
	else if (buf[0] == 'r' && buf[1] == 'b' && buf[2] == '\n')
		return (rb);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == '\n')
		return (rr);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'a' && buf[3] == '\n')
		return (rra);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'b' && buf[3] == '\n')
		return (rrb);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'r' && buf[3] == '\n')
		return (rrr);
	ERROR();
	return (none);
}
