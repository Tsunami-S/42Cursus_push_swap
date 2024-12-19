#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

#define OVERFLOW -42
#define ERROR -1

typedef struct s_stack{
	int n;
	struct s_stack *next;
} t_stack;

typedef struct s_list{
	t_stack *start_a;
	t_stack *start_b;
	t_stack *end_a;
	t_stack *end_b;
} t_list;

t_stack	*init_stack_from_one(char *str, t_list *list);
t_stack	*init_stack_from_args(int argc, char **argv, t_list *list);
void delete_stack(t_stack *stack_a, t_stack *stack_b);
void error(void);
void swap(t_list *list, char c);

#endif
