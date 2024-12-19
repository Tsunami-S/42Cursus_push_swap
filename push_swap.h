#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

#define OVERFLOW -42
#define ERROR -1

typedef struct s_list{
	int n;
	struct s_list *next;
	struct s_list *prev;
} t_list;

t_list	*init_stack_from_one(char *str);
t_list	*init_stack_from_args(int argc, char **argv);
void delete_list(t_list *start);
void error(void);

#endif
