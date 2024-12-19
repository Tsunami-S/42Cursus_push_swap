#include "push_swap.h"

static int		num_check(int n, t_list *start);
static t_list	*make_node(int n, t_list *prev);
static char		*now_pointa(char *str);

t_list	*init_stack(char *str)
{
	int		n;
	t_list	*start;
	t_list	*next;
	t_list	*prev;

	if (!str)
		return (NULL);
	n = ft_atoi(str);
	start = make_node(n, NULL);
	if (!start)
		return (error(), NULL);
	str = now_pointa(str);
	prev = start;
	while (*str)
	{
		n = ft_atoi(str);
		if (num_check(n, start) == ERROR)
			return (delete_list(start), error(), NULL);
		next = make_node(n, prev);
		if (!next)
			return (delete_list(start), error(), NULL);
		prev = next;
		str = now_pointa(str);
	}
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
	new->prev = prev;
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
