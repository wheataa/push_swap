/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:31:52 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/09 14:04:09 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	unsigned int	n_int;
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
		ranks = find_ranks(&a, &len_a);
		while (i < n_int)
		{
			printf("ranks[%i] is %i\n", i, ranks[i]);
			i++;
		}
	}
	return (0);
}
