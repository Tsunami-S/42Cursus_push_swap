#ifndef PUSH_SWAP_STRUCT_H
# define PUSH_SWAP_STRUCT_H

typedef struct s_elem
{
	int				n;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct s_stack
{
	t_elem			*start_a;
	t_elem			*start_b;
	t_elem			*end_a;
	t_elem			*end_b;
}					t_stack;

typedef struct s_count
{
	int				to_a_top;
	int				to_b_top;
	int				to_a_bottom;
	int				to_b_bottom;
}					t_count;

#endif
