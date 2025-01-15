#include "push_swap.h"

static void	init_empty_stacks(t_stack *stacks);
static int	make_num(t_stack *stacks, char *str);
static void	check_new_num(t_stack *stacks, int num);
static void	stack_elem(t_stack *stacks, int num);

void	init_stacks(t_stack *stacks, int argc, char **argv)
{
	int	num;

	init_empty_stacks(stacks);
	while (argc > 1)
	{
		argc--;
		argv++;
		while (**argv)
		{
			num = make_num(stacks, *argv);
			check_new_num(stacks, num);
			stack_elem(stacks, num);
			while (**argv && !ft_isspace(**argv))
				(*argv)++;
			while (ft_isspace(**argv))
				(*argv)++;
		}
	}
}

static void	init_empty_stacks(t_stack *stacks)
{
	stacks->start_a = NULL;
	stacks->start_b = NULL;
	stacks->end_a = NULL;
	stacks->end_b = NULL;
}

static int	make_num(t_stack *stacks, char *str)
{
	long	ans;
	int		sign;

	ans = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
	{
		str++;
		if (!*str)
			free_stacks(stacks, ERROR);
	}
	while (ft_isdigit(*str))
	{
		ans = ans * 10 + *str - '0';
		if (sign * ans > INT_MAX || sign * ans < INT_MIN)
			free_stacks(stacks, ERROR);
		str++;
	}
	if (*str && !ft_isspace(*str))
		free_stacks(stacks, ERROR);
	return (ans * sign);
}

static void	check_new_num(t_stack *stacks, int num)
{
	t_elem *node;

	node = stacks->start_a;
	if (!node)
		return ;
	while (node)
	{
		if (node->n == num)
			free_stacks(stacks, ERROR);
		node = node->next;
	}
}

static void	stack_elem(t_stack *stacks, int num)
{
	t_elem	*new;

	new = (t_elem *)malloc(sizeof(t_stack));
	if (!new)
		free_stacks(stacks, ERROR);
	new->n = num;
	new->next = NULL;
	new->prev = stacks->end_a;
	if (stacks->end_a)
		stacks->end_a->next = new;
	else
	{
		stacks->start_a = new;
		new->prev = NULL;
	}
	stacks->end_a = new;
}
