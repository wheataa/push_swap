/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:59:31 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/07 15:43:33 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ra(int	**a, int len)
{
	int	temp;
	int	i;

	i = 0;
	temp = (*a)[0];
	while (i < len - 1)
	{
		(*a)[i] = (*a)[i + 1];
		i++;
	}
	(*a)[i] = temp;
}

void	rr(int	**a, int **b, int len)
{
	ra(a, len);
	ra(b, len);
}

void	rra(int **a, int len)
{
	int	temp;
	int	i;

	i = 0;
	temp = (*a)[len - 1];
	while (i < len - 1)
	{
		(*a)[len - i - 1] = (*a)[len - i - 2];
		i++;
	}
	(*a)[0] = temp;
}

void	rrr(int **a, int **b, int len)
{
	rra(a, len);
	rra(b, len);
}

int	main(void)
{
	int	*a;
	int	*b;
	int	i = 0;
	int	j = 0;

	a = malloc(5 * sizeof(int));
	b = malloc(5 * sizeof(int));
	while (i < 5)
	{
		a[i] = i + 1;
		i++;
	}
	while (j < 5)
	{
		b[j] = j + 5;
		j++;
	}
	
	i = 0;
	j = 0;
	//ss(&a, &b);
	rrr(&a, &b, 5);
	printf("a is:\n");
	while (i < 5)
	{
		printf("%i\n", a[i]);
		i++;
	}
	printf("\nb is:\n");
	while (j < 5)
	{
		printf("%i\n", b[j]);
		j++;
	}
	return (0);
}
