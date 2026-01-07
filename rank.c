/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:22:55 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/07 17:44:02 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int	*find_rank(int	**a, int *len_a)
{
	int	*rank;
	int	i;
	int	j;
	int	rnk;
	int	max;
	int	min;

	rank = malloc(len_a * sizeof(int));
	if (!rank)
		return (NULL); // free a and b in main
	i = 0;
	min = (*a)[0];
	while (i < len_a - 1)
	{
		if ((*a)[i + 1] < (*a)[i])
			min = (*a)[i + 1];
		i++;
	}
}


int	main(void)
{
	int	*a;
	int	*b;
	int	i = 0;
	int	j = 0;
	int	len_a = 10;
	int	len_b = 0;
	int	*rank;

	a = malloc(10 * sizeof(int));
	while (i < 10)
	{
		a[i] = 10 - i;
		i++;
	}

	rank = find_rank(a);
	while (j < len_a)
	{
		printf("%i\n", rank[j]);
		j++;
	}
	return (0);
}
