#include "push_swap.h"

void make_two_pivot_go_next(t_stack *start, int size, int *large, int *small);
void make_two_pivot_go_prev(t_stack *start, int size, int *large, int *small);
int make_pivot_go_prev(t_stack *start, int count);
int make_pivot_go_next(t_stack *start, int count);

void make_two_pivot_go_next(t_stack *start, int size, int *large, int *small)
{
//	int i, max, min;
//	t_stack *now;
//	max = start->n;
//	min = start->n;
//	i = 0;
//	now = start;
//	while(i < size)
//	{
//		if(now->n < min)
//			min = now->n;
//		if(now->n > max)
//			max = now->n;
//		now = now->next;
//		i++;
//	}
//	*large = (max - min) / 3 * 2 + min;
//	*small = (max - min) / 3  + min;
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
		now = now->next;
		i++;
	}
	large_ans = total / size ;
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
		now = now->next;
	}
	small_ans = total / i;
	*large = large_ans;
	*small = small_ans;
}

void make_two_pivot_go_prev(t_stack *start, int size, int *large, int *small)
{
//	int i, max, min;
//	t_stack *now;
//	max = start->n;
//	min = start->n;
//	i = 0;
//	now = start;
//	while(i < size)
//	{
//		if(now->n < min)
//			min = now->n;
//		if(now->n > max)
//			max = now->n;
//		now = now->prev;
//		i++;
//	}
//	*large = (max - min) / 3 * 2 + min;
//	*small = (max - min) / 3  + min;

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

int make_pivot_go_prev(t_stack *start, int count)
{
	t_stack *now;
	long long total;
	long long average;
	int i;

	total = 0;
	i = 0;
	now = start;
	while(i < count)
	{
		total += now->n;
		now = now->prev;
		i++;
	}
	average = total / count;
	return (int)average;
}

int make_pivot_go_next(t_stack *start, int count)
{
	t_stack *now;
	long long  total;
	long long average;
	int i;

	total = 0;
	i = 0;
	now = start;
	while(i < count)
	{
		total += now->n;
		now = now->next;
		i++;
	}
	average = total / count;
	return (int)average;
}
