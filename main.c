/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:31:52 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/09 18:08:07 by jwheatin         ###   ########.fr       */
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
	printf("\n Check is %i\n", check);
	return (check);
}

int	*sort_bit(int *a, int n_int, int bit_pos)
{
	int	mask;
	int	i;
	int	len_b;
	int	*b;
	int	loop = n_int;

	mask = 1;
	i = 0;
	len_b = 0;
	b = malloc(n_int * sizeof(int));
	if (!b)
		return (NULL);
	while (i < loop)
	{
		printf("condition a[0] %i  & mask %i, %i\n", a[0], mask, ((a[0] & mask) >> bit_pos));
		if (!((a[0] & mask) >> bit_pos))
		{
			printf("\nPUSHING\n");
			pa(&b, &a, &len_b, &n_int);
			printf("b: %i\n", b[0]);
			int j = 0;
			while (j < n_int)
			{
				printf("a[%i] is %i\n", j, a[j]);
				j++;
			}
			j = 0;
			printf("\n");
			while (j < n_int)
			{
				printf("b[%i] is %i\n", j, b[j]);
				j++;
			}
		}
		else
		{
			printf("\nROTATING\n");
			ra(&a, &n_int);
			int j = 0;
			while (j < n_int)
			{
				printf("a[%i] is %i\n", j, a[j]);
				j++;
			}
			j = 0;
			printf("\n");
			while (j < n_int)
			{
				printf("b[%i] is %i\n", j, b[j]);
				j++;
			}
		}
		i++;
	}
	printf("\n---b--- %i\n", len_b);
	i = 0;
	while (i < len_b)
	{
		printf("stack b[%i] %i\n", i, b[i]);
		i++;
	}
	i = 0;
	while (i < len_b)
	{
		pa(&a, &b, &n_int, &len_b);
		i++;
	}
	i = 0;
	printf("\n---SORTING---\n");
	while (i < n_int)
	{
		printf("stack a[%i] %i\n", i, a[i]);
		i++;
	}
	free(b);
	return (a);
}

int	main(int argc, char **argv)
{
	int	n_int;
	int				*array;
	int				*ranks;
	int	i = 0;

	n_int = 0;
	if (argc != 2)
		write(1, "Error \n", 7);
	else
	{
		n_int = count_int(argv[1]);
		printf("%i\n", n_int);
		if (!n_int)
			return (0);
		array = alloc_fill(array, argv[1], n_int);
		if (!(dupe_check(array, n_int)))
			return (error());
		ranks = find_ranks(&array, &n_int);
		printf("\n----RANKS---- \n");
		while (i < n_int)
		{
			printf("ranks[%i] is %i\n", i, ranks[i]);
			i++;
		}
		i = 0;
		while (check_order(ranks, n_int))
		{
			ranks = sort_bit(ranks, n_int, i);
			i++;
		}
	}
	return (0);
}
