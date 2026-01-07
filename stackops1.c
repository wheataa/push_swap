/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:59:31 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/07 16:28:30 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	sa(int **a)
{
	int	temp;

	temp = *a[0];
	(*a)[0] = (*a)[1];
	(*a)[1] = temp;

}

void	ss(int **a, int **b)
{
	sa(a);
	sa(b);
}

void	pa(int **a, int **b, int len)
{
	int	i;
	
	i = 0;
	while (i < len - 1)
	{
		(*a)[i + 1] = (*a)[i];
		i++;
	}
	(*a)[0] = (*b)[0];
	(*b)[0] = 0;
		
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
		b[j] = 0;
		j++;
	}
	
	i = 0;
	j = 0;
	//ss(&a, &b);
	pa(&b, &a);
	printf("a is:\n");
	while (i < 5)
	{
		printf("%i\n", a[i]);
		i++;
	}
	printf("b is:\n");
	while (j < 5)
	{
		printf("%i\n", b[j]);
		j++;
	}
	return (0);
}
