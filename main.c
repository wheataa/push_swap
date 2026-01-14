/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:31:52 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/13 18:01:16 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(int *ranks, int len_a)
{
	int	check;
	int	i;
	int	j;

	check = 0;
	i = 0;
	while (i < len_a)
	{
		j = i + 1;
		while (j < len_a)
		{
			if (ranks[i] > ranks[j])
				check = 1;
			j++;
		}
		i++;
	}
	return (check);
}

int	*sort_bit(int *a, int n_int, int bit_pos)
{
	int	i;
	int	len_b;
	int	*b;
	int	loop;

	loop = n_int;
	i = 0;
	len_b = 0;
	b = malloc(n_int * sizeof(int));
	if (!b)
		return (NULL);
	while (i++ < loop)
	{
		if (!(a[0] & (1 << bit_pos)))
			(push(b, a, &len_b, &n_int), write(1, "pb\n", 3));
		else
			rotate(a, n_int);
	}
	i = 0;
	loop = len_b;
	while (i++ < loop)
		(push(a, b, &n_int, &len_b), write(1, "pa\n", 3));
	free(b);
	return (a);
}

int	*choose_sort(int *ranks, int n_int)
{
	int	i;

	if (n_int == 2)
		swap(ranks, n_int);
	else if (n_int == 3)
		ranks = sort3(ranks, n_int);
	else if (n_int == 4)
		ranks = sort4(ranks, n_int);
	else if (n_int == 5)
		ranks = sort5(ranks, n_int);
	else
	{
		i = 0;
		while (check_order(ranks, n_int))
			sort_bit(ranks, n_int, i++);
	}
	return (ranks);
}

int	main(int argc, char **argv)
{
	int	n_int;
	int	*array;
	int	*ranks;

	array = NULL;
	n_int = 0;
	if (argc >= 2)
	{
		n_int = choose_count(argc, argv);
		if (n_int == -1)
			return (-1);
		array = choose_alloc(array, argv, n_int, argc);
		if (!(array))
			return (error());
		if (!(dupe_check(array, n_int)))
			return (error());
		ranks = find_ranks(array, n_int);
		while (check_order(ranks, n_int))
		{
			if (!ranks)
				return (free(array), 0);
			ranks = choose_sort(ranks, n_int);
		}
		(free(ranks), free(array));
	}
	return (0);
}
