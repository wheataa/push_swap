/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:11:22 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/13 14:59:05 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

int	choose_count(int n_argc, char **s)
{
	if (n_argc == 2)
		return (count_int(s[1]));
	else
		return (count_arg(s));
}

int	count_int(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s[i] || (s[i] != '-' && !(s[i] >= '0' && s[i] <= '9')))
		return (error());
	count++;
	while (s[i])
	{
		if (((s[i] >= '0' && s[i] <= '9')
				&& (!s[i + 1] || s[i + 1] == ' '
					|| (s[i + 1] >= '0' && s[i + 1] <= '9')))
			|| (s[i] == '-' && (s[i + 1] >= '0' && s[i + 1] <= '9')))
			i++;
		else if (s[i] == ' ' && (s[i + 1] == '-'
				|| (s[i + 1] >= '0' && s[i + 1] <= '9')))
		{
			i++;
			count++;
		}
		else
			return (error());
	}
	return (count);
}

int	count_arg(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		if (s[i][j] && s[i][j] != '-' && !(s[i][j] >= '0' && s[i][j] <= '9'))
			return (error());
		j++;
		while (s[i][j])
		{
			if (s[i][j] >= '0' && s[i][j] <= '9')
				j++;
			else
				return (error());
		}
		i++;
	}
	return (i - 1);
}

long int	ps_atoi(char *s)
{
	int			sign;
	long int	num;

	num = 0;
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		if (num * sign < -2147483648 || num * sign > 2147483647)
			return (-2147483649);
		s++;
	}
	return (num * sign);
}
