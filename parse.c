/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:11:22 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/09 14:00:32 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	error(void)
{
	write(1, "Error \n", 7);
	return (0);
}

int	dupe_check(int	*array, int n_int)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_int - 1)
	{
		j = i + 1;
		while (j < n_int)
		{
			if (array[i] == array[j])
			{
				free(array);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

unsigned int	count_int(char const *s)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (s[i] && s[i] != '-' && !(s[i] >= '0' && s[i] <= '9'))
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

int	ps_atoi(char *s)
{
	int		sign;
	size_t	num;

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
		s++;
	}
	return (num * sign);
}

int	*alloc_fill(int *array, char *s, unsigned int n_int)
{
	unsigned int	i;
	int				count;
	int				sign;

	count = 0;
	array = malloc((n_int + 1) * sizeof(int));
	if (!array)
		return (0);
	while (*s)
	{
		array[count] = ps_atoi(&(*s));
		while (*s == '-' || (*s >= '0' && *s <= '9'))
			s++;
		printf("array[%i] is %i\n", count, array[count]);
		if (*s)
			s++;
		count++;
	}
	array[count] = 0;
	return (array);
}
