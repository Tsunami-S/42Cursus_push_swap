#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list{
	int n;
	struct s_list *next;
	struct s_list *prev;
}

t_list *init_stack(char *str);
void delete_list(t_list *start);

#endif
