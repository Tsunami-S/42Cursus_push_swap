/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:03 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/02 21:40:32 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define OVERFLOW -42
# define ERROR -1
# define SUCCESS 1

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_list
{
	t_stack			*start_a;
	t_stack			*start_b;
	t_stack			*end_a;
	t_stack			*end_b;
	t_stack			*sorted_sta;
	t_stack			*sorted_ena;
	int				sorted_num;
}					t_list;

typedef enum e_act
{
	none = 0,
	sa = 1,
	sb = 2,
	ss = 3,
	pa = 11,
	pb = 12,
	ra = 21,
	rb = 22,
	rr = 23,
	rra = 31,
	rrb = 32,
	rrr = 33,
	init = 42
}					t_act;

/* push_swap */
void push_swap(t_list *list);
void ash(t_list *list, t_act act);
void write_command(t_act act);
void select_act(t_list *list, t_act act);

void sort_three(t_list *list, t_stack *top, t_stack *middle, t_stack *bottom);
void sort_six(t_list *list, int count);
void search_max_and_min(t_stack *start, int *max, int *min);
int					issorted(t_list *list);
int					stack_count(t_stack *stack);
/* list_utils */
void				error(void);
void				list_init(t_list *list);
void				delete_stack(t_list *list);
int					init_stack_from_one(char *str, t_list *list);
int					init_stack_from_args(int argc, char **argv, t_list *list);
/* comannds */
void				swap(t_list *list, t_act act);
void				push(t_list *list, t_act act);
void				rotate(t_list *list, t_act act);
void				reverse(t_list *list, t_act act);
/* ft_utils */
long long			ft_atol(const char *nptr);
int					ft_issign(char c);
int					ft_isspace(char c);
int					ft_isdigit(int c);

#endif
