#include "push_swap.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}
