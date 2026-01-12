/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:31:52 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/12 12:42:14 by jwheatin         ###   ########.fr       */
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
	//printf("\n Check is %i\n", check);
	return (check);
}

int	*sort_bit(int *a, int n_int, int bit_pos)
{
	int	mask;
	int	i;
	int	len_b;
	int	*b;
	int	loop = n_int;

	mask = 1 << bit_pos;
	i = 0;
	len_b = 0;
	b = malloc(n_int * sizeof(int));
	if (!b)
		return (NULL);
	while (i < n_int)
	{
		b[i] = 0;
		i++;
	}
	i = 0;
	while (i < loop)
	{
		//printf("condition a[0] %i  & mask %i, %i\n", a[0], mask, ((a[0] & mask) >> bit_pos));
		if (!((a[0] & mask) >> bit_pos))
		{
			//printf("\nSTART PUSHING\n");
			pa(&b, &a, &len_b, &n_int);
			printf("pb\n");
			//printf("b: %i\n", b[0]);
			int j = 0;
			while (j < n_int)
			{
		//		printf("a[%i] is %i\n", j, a[j]);
				j++;
			}
			j = 0;
			//printf("\n");
			while (j < len_b)
			{
		//		printf("b[%i] is %i\n", j, b[j]);
				j++;
			}
		//	printf("\nEND PUSHING\n");
		}
		else
		{
		//	printf("\nROTATING\n");
			ra(&a, &n_int);
			printf("ra\n");
			int j = 0;
			while (j < n_int)
			{
		//		printf("a[%i] is %i\n", j, a[j]);
				j++;
			}
			j = 0;
		//	printf("\n");
			while (j < len_b)
			{
		//		printf("b[%i] is %i\n", j, b[j]);
				j++;
			}
		}
		i++;
	}
	i = 0;
	int count_b = len_b;
	while (i < count_b)
	{
		//printf("Pushing b back to a: a[0] %i and b[0] %i\n", a[0], b[0]);
		//printf("Pushing b back to a: n_int %i and len_b %i\n", n_int, len_b);
		pa(&a, &b, &n_int, &len_b);
		printf("pa\n");
		i++;
		int j = 0;
		while (j < n_int)
		{
		//	printf("Post push back step stack a[%i] %i\n", j, a[j]);
			j++;
		}
	}
	i = 0;
	while (i < n_int)
	{
		//printf("stack a[%i] %i\n", i, a[i]);
		i++;
	}
	//printf("\n");
	i = 0;
	while (i < len_b)
	{
		//printf("stack b[%i] %i\n", i, b[i]);
		i++;
	}
	//printf("At end of loop, len_a %i and len_b %i\n", n_int, len_b);
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
		//printf("%i\n", n_int);
		if (!n_int)
			return (0);
		array = alloc_fill(array, argv[1], n_int);
		if (!(dupe_check(array, n_int)))
			return (error());
		ranks = find_ranks(&array, &n_int);
		//printf("\n----RANKS---- \n");
		while (i < n_int)
		{
		//	printf("ranks[%i] is %i\n", i, ranks[i]);
			i++;
		}
		i = 0;
		int j = 0;
		//printf("\n---SORTING---\n");
		//while (j < 4)
		while (check_order(ranks, n_int))
		{
			//printf("\nSTART SORT\n");
			ranks = sort_bit(ranks, n_int, j);
			//printf("\nEND SORT\n");
			//i++;
			j++;
		}
		i = 0;
		while (i < n_int)
		{
		//	printf("stack a[%i] %i\n", i, ranks[i]);
			i++;
		}
		//printf("\n");
		free(ranks);
		free(array);
	}
	return (0);
}
