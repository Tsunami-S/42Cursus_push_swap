#include "push_swap.h"

static void	write_command(t_act act);

void	compress_cmds(t_stack *stacks, t_act act)
{
	static t_act	prev;

	select_act(stacks, act);
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

void	consecutive_cmds(t_stack *stacks, t_act act, int count)
{
	while (count--)
		compress_cmds(stacks, act);
}

void	select_act(t_stack *stacks, t_act act)
{
	if (act == sa || act == sb || act == ss)
		swap(stacks, act);
	else if (act == pa || act == pb)
		push(stacks, act);
	else if (act == ra || act == rb || act == rr)
		rotate(stacks, act);
	else if (act == rra || act == rrb || act == rrr)
		reverse(stacks, act);
}

static void	write_command(t_act act)
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
