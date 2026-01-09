/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:35:33 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/09 18:08:11 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	error(void);
int	dupe_check(int *array, int n_int);
unsigned int	count_int(char const *s);
int	ps_atoi(char *s);
int	*alloc_fill(int *array, char *s, unsigned int n_int);
int	*find_ranks(int **a, int *len_a);
void	sa(int **a, int len_a);
void	ss(int **a, int **b, int len_a, int len_b);
void	pa(int **a, int **b, int *len_a, int *len_b);
void	ra(int **a, int *len_a);
void	rr(int **a, int **b, int *len_a, int *len_b);
void	rra(int **a, int *len_a);
void	rrr(int **a, int **b, int *len_a, int *len_b);

#endif

