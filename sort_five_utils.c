/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:35:29 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/13 18:01:11 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_one(int **ranks, int n_int)
{
	if ((*ranks)[1] == 1)
		rotate(ranks, &n_int);
	else if ((*ranks)[2] == 1)
		(rotate(ranks, &n_int), rotate(ranks, &n_int));
	else if ((*ranks)[3] == 1)
		(rrotate(ranks, &n_int), rrotate(ranks, &n_int));
	else if ((*ranks)[4] == 1)
		rrotate(ranks, &n_int);
}

void	find_two(int **ranks, int n_int)
{
	if ((*ranks)[1] == 2)
		rotate(ranks, &n_int);
	else if ((*ranks)[2] == 2)
		(rotate(ranks, &n_int), rotate(ranks, &n_int));
	else if ((*ranks)[3] == 2)
		rrotate(ranks, &n_int);
}

int	*check_return(int *ranks, int *b, int n_int, int len_b)
{
	int	i;
	int	count;

	i = 0;
	count = len_b;
	while (i < count)
	{
		(push(&ranks, &b, &n_int, &len_b), write(1, "pa\n", 3));
		i++;
	}
	free(b);
	return (ranks);
}
