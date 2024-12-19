/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:03 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/20 01:22:13 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
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
}					t_list;

typedef enum e_act
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}					t_act;

void				push_swap(t_list *list);
int					init_stack_from_one(char *str, t_list *list);
int					init_stack_from_args(int argc, char **argv, t_list *list);
void				error(void);
/* list_utils */
void				delete_stack(t_list *list);
void				list_init(t_list *list);
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
