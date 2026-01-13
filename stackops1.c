/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:59:31 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/13 12:37:43 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int **a, int len_a)
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
	swap(a, len_a);
	swap(b, len_b);
}

void	push(int **pushto, int **pushfrom, int *len_pt, int *len_pf)
{
	int	i;

	if (!(*len_pf))
		return ;
	i = 0;
	while (i < *len_pt)
	{
		(*pushto)[*len_pt - i] = (*pushto)[*len_pt - i - 1];
		i++;
	}
	(*pushto)[0] = (*pushfrom)[0];
	i = 0;
	while (i < *len_pf - 1)
	{
		(*pushfrom)[i] = (*pushfrom)[i + 1];
		i++;
	}
	(*pushfrom)[i] = 0;
	(*len_pt)++;
	(*len_pf)--;
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
