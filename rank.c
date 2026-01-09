/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:22:55 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/09 14:05:11 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
		//printf("a[%i] rank ranks[%i]: %i\n", i, i, ranks[i]);
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
