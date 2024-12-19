#include "push_swap.h"

static int		num_check(int n, t_list *start);
static t_list	*make_node(int n, t_list *prev);
static char		*now_pointa(char *str);

t_stack	*init_stack_from_one(char *str, t_list *list)
{
	int		n;
	t_list	*next;
	t_list	*prev;

	n = ft_atoi(str);
	prev = make_node(n, NULL);
	if (!prev)
		return (error(), NULL);
	str = now_pointa(str);
	list->start_a = prev;
	while (*str)
	{
		n = ft_atoi(str);
		if (num_check(n, start) == ERROR)
			return (delete_stack(list), error(), NULL);
		next = make_node(n, prev);
		if (!next)
			return (delete_stack(list), error(), NULL);
		prev = next;
		str = now_pointa(str);
	}
	list->end_a = prev;
	return (start);
}

t_stack	*init_stack_from_args(int argc, char **argv, t_list *list)
{
	int		i;
	int		n;
	t_list	*next;
	t_list	*prev;

	n = ft_atoi(argv[1]);
	prev = make_node(n, NULL);
	if (!prev)
		return (error(), NULL);
	list->start_a = prev;
	i = 2;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (num_check(n, start) == ERROR)
			return (delete_stack(list), error(), NULL);
		next = make_node(n, prev);
		if (!next)
			return (delete_stack(list), error(), NULL);
		prev = next;
		i++;
	}
	list->end_a = prev;
	return (start);
}

static int	num_check(int n, t_list *start)
{
	while (start)
	{
		if (start->n == n)
			return (-1);
		start = start->next;
	}
	return (0);
}

static t_list	*make_node(int n, t_list *prev)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->n = n;
	if(prev)
		prev->next = new;
	new->next = NULL;
	return (new);
}

static char	*now_pointa(char *str)
{
	while (*str && is_space(*str))
		str++;
	if (*str && is_sign(*str))
		str++;
	while (*str && is_digit(*str))
		str++;
	while (*str && is_space(*str))
		str++;
	return (str);
}
