/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:35:33 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/09 14:04:46 by jwheatin         ###   ########.fr       */
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

#endif

