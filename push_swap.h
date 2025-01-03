/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:03 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/03 19:28:05 by tssaito          ###   ########.fr       */
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
t_stack				*exec_pa_and_rrb(t_list *list, t_stack *en_b, int medium);
t_stack				*exec_pa_and_rb(t_list *list, t_stack *en_b, int medium);
t_stack				*exec_pb_and_rra(t_list *list, t_stack *en_b, int medium);
t_stack				*exec_pb_and_ra(t_list *list, t_stack *en_b, int medium);
void				pb_and_ra(t_list *list, t_stack *en_a, int medium);
void				pa_and_rb(t_list *list, t_stack *en_b, int medium);
void				pa_and_rrb(t_list *list, t_stack *en_b, int medium);
void				pb_and_rra(t_list *list, t_stack *en_a, int medium);

void				push_swap(t_list *list);
void				ash(t_list *list, t_act act);
void				write_command(t_act act);
void				select_act(t_list *list, t_act act);
void				sort_small_stack(t_list *list, int count);
void				reverse_to_start_a(t_list *list, int count);
void				merge(t_list *list, int len_a, int len_b);
/* list_utils */
void				error(void);
void				list_init(t_list *list);
void				delete_stack(t_list *list);
int					issorted_a(t_list *list);
int					issorted(t_stack *start, t_stack *end, int sign);
int					init_stack_from_one(char *str, t_list *list);
int					init_stack_from_args(int argc, char **argv, t_list *list);
int					make_medium(t_stack *start, t_stack *end);
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
