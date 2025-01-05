/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:03 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/05 14:56:13 by tssaito          ###   ########.fr       */
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
# define SUCCESS 0
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
	t_stack			*sorted_sta;
	t_stack			*sorted_ena;
	int				sorted_num;
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
void make_stack_a_smaller(t_list *list, int start_size);
void sort_a_top(t_list *list, int start_size);
void sort_a_bottom(t_list *list, int start_size);
void rev_mid(t_list *list, int count);
void rev_small(t_list *list, int count);
void	sort_small_stack(t_list *list, int count);
void sort_small_stack_bottom(t_list *list, int ra_count);
void three_small_sort(t_list *list, int count);
void three_mid_sort(t_list *list, int count);

void				ash(t_list *list, t_act act);
void				write_command(t_act act);
void				select_act(t_list *list, t_act act);

void	reverse_to_start_a(t_list *list, int count);
void	merge(t_list *list, int len_a, int len_b);
int	issorted_a(t_list *list);
int issorted_go_next(t_stack *start, int count);
int issorted_go_prev(t_stack *start, int count);
void make_two_pivot_go_next(t_stack *start, int size, int *large, int *small);
void make_two_pivot_go_prev(t_stack *start, int size, int *large, int *small);
int make_pivot_go_prev(t_stack *start, int count);
int make_pivot_go_next(t_stack *start, int count);
/* list_utils */
void				error(void);
void				list_init(t_list *list);
void				delete_stack(t_list *list);
int					init_stack_from_one(char *str, t_list *list);
int					init_stack_from_args(int argc, char **argv, t_list *list);
int					stack_count(t_stack *stack);
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
