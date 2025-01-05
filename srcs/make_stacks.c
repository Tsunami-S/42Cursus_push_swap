/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:32 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 22:17:40 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int		num_check(int n, t_stack *start);
static t_stack	*make_node(long long n, t_stack *prev);
static char		*now_pointa(char *str);

int	init_stack_from_one(char *str, t_list *list)
{
	long long	n;
	t_stack		*next;
	t_stack		*prev;

	n = ft_atol(str);
	prev = make_node(n, NULL);
	if (!prev)
		return (error(), ERROR);
	str = now_pointa(str);
	list->start_a = prev;
	while (*str)
	{
		n = ft_atol(str);
		if (num_check(n, list->start_a) == ERROR)
			return (delete_stack(list), error(), ERROR);
		next = make_node(n, prev);
		if (!next)
			return (delete_stack(list), error(), ERROR);
		prev = next;
		str = now_pointa(str);
	}
	list->end_a = prev;
	return (SUCCESS);
}

int	init_stack_from_args(int argc, char **argv, t_list *list)
{
	int			i;
	long long	n;
	t_stack		*next;
	t_stack		*prev;

	n = ft_atol(argv[1]);
	prev = make_node(n, NULL);
	if (!prev)
		return (error(), ERROR);
	list->start_a = prev;
	i = 2;
	while (i < argc)
	{
		n = ft_atol(argv[i]);
		if (num_check(n, list->start_a) == ERROR)
			return (delete_stack(list), error(), ERROR);
		next = make_node(n, prev);
		if (!next)
			return (delete_stack(list), error(), ERROR);
		prev = next;
		i++;
	}
	list->end_a = prev;
	return (SUCCESS);
}

static int	num_check(int n, t_stack *start)
{
	while (start)
	{
		if (start->n == n)
			return (ERROR);
		start = start->next;
	}
	return (SUCCESS);
}

static t_stack	*make_node(long long n, t_stack *prev)
{
	t_stack	*new;

	if (n < INT_MIN || n > INT_MAX)
		return (NULL);
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = prev;
	if (prev)
		prev->next = new;
	new->next = NULL;
	return (new);
}

static char	*now_pointa(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	if (*str && ft_issign(*str))
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	while (*str && ft_isspace(*str))
		str++;
	return (str);
}
