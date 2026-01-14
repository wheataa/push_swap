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

int	*sort5(int *ranks, int n_int)
{
	int	*b;
	int	len_b;
	int	i;

	len_b = 0;
	find_one(ranks, n_int);
	if (!check_order(ranks, n_int))
		return (ranks);
	b = malloc(2 * sizeof(int));
	if (!b)
		return (NULL);
	(push(b, ranks, &len_b, &n_int), write(1, "pb\n", 3));
	find_two(ranks, n_int);
	if (!check_order(ranks, n_int))
		return (check_return(ranks, b, n_int, len_b));
	(push(b, ranks, &len_b, &n_int), write(1, "pb\n", 3));
	i = 0;
	while (i++ < 3)
		ranks[i - 1] -= 2;
	ranks = sort3(ranks, n_int);
	while (i-- > 1)
		ranks[i - 1] += 2;
	return (check_return(ranks, b, n_int, len_b));
}

int	*sort4(int *ranks, int n_int)
{
	int	*b;
	int	len_b;
	int	i;

	i = 0;
	if (ranks[1] == 1)
		rotate(ranks, n_int);
	else if (ranks[2] == 1)
		(rotate(ranks, n_int), rotate(ranks, n_int));
	else if (ranks[3] == 1)
		rrotate(ranks, n_int);
	if (!check_order(ranks, n_int))
		return (ranks);
	b = malloc(sizeof(int));
	if (!b)
		return (NULL);
	len_b = 0;
	(push(b, ranks, &len_b, &n_int), write(1, "pb\n", 3));
	while (i++ < 3)
		ranks[i - 1]--;
	ranks = sort3(ranks, n_int);
	while (i-- > 1)
		ranks[i - 1]++;
	return (check_return(ranks, b, n_int, len_b));
}

int	*sort3(int *ranks, int n_int)
{
	if (ranks[0] == 1)
		(rotate(ranks, n_int), swap(ranks, n_int), rrotate(ranks, n_int));
	else if (ranks[0] == 2 && ranks[1] == 1)
		swap(ranks, n_int);
	else if (ranks[0] == 2 && ranks[1] == 3)
		rrotate(ranks, n_int);
	else if (ranks[0] == 3 && ranks[1] == 1)
		rotate(ranks, n_int);
	else if (ranks[0] == 3 && ranks[1] == 2)
		(rotate(ranks, n_int), swap(ranks, n_int));
	return (ranks);
}
