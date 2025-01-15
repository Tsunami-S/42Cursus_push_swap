#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_macro.h"
# include "push_swap_struct.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* push_swap */
void	push_swap(t_stack *stacks);
void	sort_few_elems(t_stack *stacks, int count);
void	make_stack_a_smaller(t_stack *stacks, int start_size);
void	sort_stack_a_top(t_stack *stacks, int start_size);
void	sort_stack_a_bottom(t_stack *stacks, int start_size);
void	sort_stack_b_top(t_stack *stacks, int count);
void	sort_stack_b_bottom(t_stack *stacks, int count);
void	split_stack_a_top(t_stack *stacks, int size, t_count *act_count);
void	split_stack_a_bottom(t_stack *stacks, int size, t_count *act_count);
void	split_stack_b_top(t_stack *stacks, int size, t_count *act_count);
void	split_stack_b_bottom(t_stack *stacks, int size, t_count *act_count);
/* sort_utils */
void	init_act_count(t_count *act_count);
void	make_pivots(t_elem *start, int size, int *large, int *small);
int		count_elems(t_elem *start, t_elem *end);
t_elem	*back_to_prev(t_elem *start, int count);
t_order	is_stack_sorted(t_elem *start, int count);
/* stack_utils */
void	init_stacks(t_stack *stacks, int argc, char **argv);
void	free_stacks(t_stack *stacks, t_check check);
/* compress_cmds */
void	compress_cmds(t_stack *stacks, t_act act);
void	consecutive_cmds(t_stack *stacks, t_act act, int count);
void	select_act(t_stack *stacks, t_act act);
/* comannds */
void	swap(t_stack *stacks, t_act act);
void	push(t_stack *stacks, t_act act);
void	rotate(t_stack *stacks, t_act act);
void	reverse(t_stack *stacks, t_act act);
/* ft_utils */
int		ft_isspace(char c);
int		ft_isdigit(int c);
/* bonus */
void	checker(t_stack *stacks);

#endif
