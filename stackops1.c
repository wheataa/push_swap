/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:59:31 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/09 18:08:14 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	sa(int **a, int len_a)
{
	int	temp;

	if (len_a <= 1)
		return ;
	temp = *a[0];
	(*a)[0] = (*a)[1];
	(*a)[1] = temp;

}

void	ss(int **a, int **b, int len_a, int len_b)
{
	sa(a, len_a);
	sa(b, len_b);
}

void	pa(int **a, int **b, int *len_a, int *len_b)
{
	int	i;
	
	if (!*len_b)
		return ;
	i = 0;
	while (i < *len_a)
	{
		(*a)[*len_a - i] = (*a)[*len_a - i - 1];
		i++;
	}
	i = 0;
	if (*len_b > 0)
		rra(b, len_b);
	(*a)[0] = (*b)[0];
	i = 0;
	while (i < *len_b - 1)
	{
		(*b)[i] = (*b)[i + 1];
		i++;
	}
	(*b)[i] = 0;
	*len_a++;
	printf("len_b is %i\n", *len_a);
	*len_b--;
		
}

/*int	main(void)
{
	int	*a;
	int	*b;
	int	i = 0;
	int	j = 0;
	int	len_a = 10;
	int	len_b = 0;

	a = malloc(10 * sizeof(int));
	b = malloc(10 * sizeof(int));
	while (i < 5)
	{
		a[i] = i + 1;
		i++;
	}
	while (i < 10)
	{
		a[i] = 0;
		i++;
	}
	while (j < 5)
	{
		b[j] = j + 6;
		j++;
	}
	while (j < 10)
	{
		b[j] = 0;
		j++;
	}
	
	i = 0;
	j = 0;
	//ss(&a, &b);
	pa(&b, &a, &len_b, &len_a);
	printf("a is:\n");
	while (i < 10)
	{
		printf("%i\n", a[i]);
		i++;
	}
	printf("b is:\n");
	while (j < 10)
	{
		printf("%i\n", b[j]);
		j++;
	}
	return (0);
}*/
