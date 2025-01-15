#ifndef PUSH_SWAP_MACRO_H
# define PUSH_SWAP_MACRO_H

typedef enum e_check
{
	ERROR,
	SUCCESS	
}	t_check;

typedef enum e_order
{
	ASCENDING,
	DESCENDING,
	UNORDERED
}	t_order;

typedef enum e_act
{
	none,
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

#endif
