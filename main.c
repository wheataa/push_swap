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
			(push(&b, &a, &len_b, &n_int), write(1, "pb\n", 3));
		else
			rotate(&a, &n_int);
	}
	i = 0;
	loop = len_b;
	while (i++ < loop)
		(push(&a, &b, &n_int, &len_b), write(1, "pa\n", 3));
	free(b);
	return (a);
}

int	main(int argc, char **argv)
{
	int	n_int;
	int	*array;
	int	*ranks;
	//int	i;
	array = NULL;
	//i = 0;
	n_int = 0;
	if (argc >= 2)
	{
		n_int = choose_count(argc, argv);
		if (!n_int)
			return (0);
		array = choose_alloc(array, argv, n_int, argc);
		if (!(array))
			return (error());
		if (!(dupe_check(array, n_int)))
			return (error());
		ranks = find_ranks(&array, &n_int);
		ranks = sort4(ranks, n_int);
		//while (i++ < n_int)
		//	printf("ranks[%i] %i\n", i-1, ranks[i-1]);
		//while (check_order(ranks, n_int))
		//	ranks = sort_bit(ranks, n_int, i++);
		(free(ranks), free(array));
	}
	return (0);
}
