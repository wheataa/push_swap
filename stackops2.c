/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:59:31 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/07 17:16:35 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ra(int	**a, int *len_a)
{
	int	temp;
	int	i;

	if (*len_a <= 1)
		return ;
	i = 0;
	temp = (*a)[0];
	while (i < *len_a - 1)
	{
		(*a)[i] = (*a)[i + 1];
		i++;
	}
	(*a)[i] = temp;
}

void	rr(int	**a, int **b, int *len_a, int *len_b)
{
	ra(a, len_a);
	ra(b, len_b);
}

void	rra(int **a, int *len_a)
{
	int	temp;
	int	i;

	if (*len_a <= 1)
		return ;
	i = 0;
	temp = (*a)[*len_a - 1];
	while (i < *len_a - 1)
	{
		(*a)[*len_a - i - 1] = (*a)[*len_a - i - 2];
		i++;
	}
	(*a)[0] = temp;
}

void	rrr(int **a, int **b, int *len_a, int *len_b)
{
	rra(a, len_a);
	rra(b, len_b);
}

int	main(void)
{
	int	*a;
	int	*b;
	int	i = 0;
	int	j = 0;
	int	len_a = 5;
	int	len_b = 5;

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
		b[j] = j + 5;
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
	rr(&a, &b, &len_a, &len_b);
	printf("a is:\n");
	while (i < 10)
	{
		printf("%i\n", a[i]);
		i++;
	}
	printf("\nb is:\n");
	while (j < 10)
	{
		printf("%i\n", b[j]);
		j++;
	}
	return (0);
}
