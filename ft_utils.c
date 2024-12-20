/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:29 by tssaito           #+#    #+#             */
/*   Updated: 2024/12/20 15:55:23 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol(const char *nptr)
{
	long long	ans;
	int			sign;

	ans = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		if (sign > 0 && (ans > LONG_MAX / 10 || (ans == LONG_MAX / 10 && *nptr
					- '0' > LONG_MAX % 10)))
			return (LONG_MAX);
		else if (sign < 0 && (-ans < LONG_MIN / 10 || (-ans == LONG_MIN / 10
					&& -(*nptr - '0') < LONG_MIN % 10)))
			return (LONG_MIN);
		ans = ans * 10 + *nptr - '0';
		nptr++;
	}
	return (ans * sign);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}
