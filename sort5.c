/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:35:29 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/13 18:01:11 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	*sort5(int *ranks)
{
	push 1 and 2 to b
	sort a using sort 3. 
	swap b if needed
	push back

}*/

// add write commands
int	*sort4(int *ranks, int n_int)
{
	int	*b;
	int	len_b;
	int	i;

	i = 0;
	if (ranks[1] == 1)
		rotate(&ranks, &n_int);
	else if (ranks[2] == 1)
		(rotate(&ranks, &n_int), rotate(&ranks, &n_int));
	else if (ranks[3] == 1)
		rrotate(&ranks, &n_int);
	if (!check_order(ranks, n_int))
		return (ranks);
	b = malloc(sizeof(int));
	if (!b)
		return (NULL);
	len_b = 0;
	(push(&b, &ranks, &len_b, &n_int), write(1, "pb\n", 3));
	while (i++ < 3)
		ranks[i - 1]--;
	ranks = sort3(ranks, n_int);
	while (i-- > 1)
		ranks[i - 1]++;
	(push(&ranks, &b, &n_int, &len_b), write(1, "pa\n", 3));
	free(b);
	return (ranks);
}

int	*sort3(int *ranks, int n_int)
{
	if (ranks[0] == 1)
		(rotate(&ranks, &n_int), swap(&ranks, n_int), rrotate(&ranks, &n_int));
	else if (ranks[0] == 2 && ranks[1] == 1)
		swap(&ranks, n_int);
	else if (ranks[0] == 2 && ranks[1] == 3)
		rrotate(&ranks, &n_int);
	else if (ranks[0] == 3 && ranks[1] == 1)
		rotate(&ranks, &n_int);
	else if (ranks[0] == 3 && ranks[1] == 2)
		(rotate(&ranks, &n_int), swap(&ranks, n_int));
	return (ranks);
}
