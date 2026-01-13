/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:22:55 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/13 13:43:19 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*choose_alloc(int *array, char **s, int n_int, int n_argc)
{
	if (n_argc == 2)
		return (alloc_fill1(array, s[1], n_int));
	else
		return (alloc_fill2(array, s, n_int));
}

int	*alloc_fill2(int *array, char **s, int n_int)
{
	int			i;
	int			j;

	i = 1;
	array = malloc(n_int * sizeof(int));
	if (!array)
		return (0);
	while (i <= n_int)
	{
		j = 0;
		while (s[i][j])
		{
			if (ps_atoi(&(s[i][j])) == -2147483649)
				return (free(array), NULL);
			array[i - 1] = ps_atoi(&s[i][j]);
			while (s[i][j] == '-' || (s[i][j] >= '0' && s[i][j] <= '9'))
				j++;
			if (s[i][j])
				j++;
		}
		i++;
	}
	return (array);
}

int	*alloc_fill1(int *array, char *s, int n_int)
{
	int			count;

	count = 0;
	array = malloc(n_int * sizeof(int));
	if (!array)
		return (0);
	while (*s)
	{
		if (ps_atoi(&(*s)) == -2147483649)
			return (free(array), NULL);
		array[count] = ps_atoi(&(*s));
		while (*s == '-' || (*s >= '0' && *s <= '9'))
			s++;
		if (*s)
			s++;
		count++;
	}
	return (array);
}

int	*find_ranks(int **a, int *len_a)
{
	int	i;
	int	*ranks;
	int	j;

	i = 0;
	ranks = malloc((*len_a) * sizeof(int));
	if (!ranks)
		return (NULL);
	while (i < *len_a)
	{
		ranks[i] = 1;
		j = 0;
		while (j < *len_a)
		{
			if (j != i)
			{
				if ((*a)[i] > (*a)[j])
					ranks[i]++;
			}
			j++;
		}
		i++;
	}
	return (ranks);
}
/*
int	main(void)
{
	int	*a;
	int	*b;
	int	i = 0;
	int	j = 0;
	int	len_a = 10;
	int	len_b = 0;
	int	*ranks;

	a = malloc(10 * sizeof(int));
	if (!a)
		return (0);
	printf("checkpoint 1\n");
	while (i < 5)
	{
		a[i] = (i * 2);
		i++;
	}
	while (i < 10)
	{
		a[i] = (10 - i) * 2 + 1;
		i++;
	}
	printf("checkpoint 2\n");
	ranks = find_ranks(&a, &len_a);
	while (j < len_a)
	{
		printf("Ranks: %i\n", ranks[j]);
		j++;
	}
	return (0);
}*/
