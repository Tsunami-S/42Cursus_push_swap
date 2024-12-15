#include "push_swap.h"

t_list *init_stack(char *str)
{
	int n;
	t_list *start;
	t_list *next;
	t_list *prev;

	if(!str)
		return NULL;
	n = ft_atoi(str);
	start = make_node(n, NULL);
	if(!start)
		return ERROR;
	str = now_pointa(str);
	prev = start;
	while(*str)
	{
		n = ft_atoi(str);
		if(num_check == ERROR)
			return delete_list(start), NULL;
		next = make_node(n, prev);
		if(!next)
			return delete_list(start), NULL;
		prev = next;
		str = now_pointa(str);
	}
	return start;
}

int num_check(int n, t_list *start)
{
	while(start)
	{
		if(start->n == n)
			return -1;
		start = start->next;
	}
	return 0;
}

t_list *make_node(int n, t_list *prev)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if(!new)
		return NULL;
	new->n = n;
	new->prev = prev;
	prev->next = new;
	new->next = NULL;
	return new;
}

void delete_list(t_list *start)
{
	t_list *tmp;

	while(start)
	{
		tmp = start;
		start = start->next;
		free(tmp);
	}
}

char *now_pointa(char *str)
{
	if (*str && is_space(*str))
		str++;
	if(
