#include "push_swap.h"

void make_two_pivot_go_next(t_stack *start, int size, int *large, int *small)
{
	t_stack *now;
	long long total;
	int i;

	total = 0;
	i = 0;
	now = start;
	while(i++ < size)
	{
		total += now->n;
		now = now->next;
	}
	*large = total / size ;
	total = 0;
	i = 0;
	now = start;
	while(size--)
	{
		if(now->n < *large)
		{
			i++;
			total += now->n;
		}
		now = now->next;
	}
	*small = total / i;
}

void make_two_pivot_go_prev(t_stack *start, int size, int *large, int *small)
{
	t_stack *now;
	long long total;
	long long large_ans;
	long long small_ans;
	int i;

	total = 0;
	i = 0;
	now = start;
	while(i < size)
	{
		total += now->n;
		now = now->prev;
		i++;
	}
	large_ans = total / size;
	total = 0;
	i = 0;
	now = start;
	while(size--)
	{
		if(now->n < large_ans)
		{
			i++;
			total += now->n;
		}
		now = now->prev;
	}
	small_ans = total / i;
	*large = large_ans;
	*small = small_ans;
}
