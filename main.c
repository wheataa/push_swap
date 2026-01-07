/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:31:52 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/07 13:40:38 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	unsigned int	n_int;
	int				*array;

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
	}
	return (0);
}
