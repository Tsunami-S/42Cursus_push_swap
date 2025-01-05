/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:03 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/06 00:35:50 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define OVERFLOW -42
# define SUCCESS 0
# define ERROR -1
# define PLUS 100
# define MINUS -100

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
}					t_list;

typedef enum e_act
{
	init = 0,
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
	none = 42
}					t_act;

/* push_swap */
void				push_swap(t_list *list);
void				make_stack_a_smaller(t_list *list, int start_size);
void				sort_a_top(t_list *list, int start_size);
void				sort_a_bottom(t_list *list, int start_size);
void				sort_b_top(t_list *list, int count);
void				sort_b_bottom(t_list *list, int count);
void				sort_small_stack(t_list *list, int count);
void				sort_small_a_bottom(t_list *list, int count);
void				sort_small_b_top(t_list *list, int count);
void				sort_small_b_bottom(t_list *list, int count);
/* sort_utils */
int					stack_count(t_stack *stack);
void				make_pivot_go_next(t_stack *start, int size, int *large,
						int *small);
void				make_pivot_go_prev(t_stack *start, int size, int *large,
						int *small);
int					issorted_a(t_list *list);
int					issorted_go_next(t_stack *start, int count);
int					issorted_go_prev(t_stack *start, int count);
/* list_utils */
void				error(void);
void				list_init(t_list *list);
void				delete_stack(t_list *list);
int					init_stack_from_one(char *str, t_list *list);
int					init_stack_from_args(int argc, char **argv, t_list *list);
/* compress_cmds */
void				compress_cmds(t_list *list, t_act act);
void				consecutive_cmds(t_list *list, t_act act, int count);
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
