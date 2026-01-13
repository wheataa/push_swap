/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwheatin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:35:33 by jwheatin          #+#    #+#             */
/*   Updated: 2026/01/13 13:37:33 by jwheatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

int			error(void);
int			dupe_check(int *array, int n_int);
int			count_int(char *s);
long int	ps_atoi(char *s);
int			*alloc_fill1(int *array, char *s, int n_int);
int			*find_ranks(int **a, int *len_a);
void		swap(int **a, int len_a);
void		ss(int **a, int **b, int len_a, int len_b);
void		push(int **pushto, int **pushfrom, int *len_pt, int *len_pf);
void		rotate(int **a, int *len_a);
void		rr(int **a, int **b, int *len_a, int *len_b);
void		rrotate(int **a, int *len_a);
void		rrr(int **a, int **b, int *len_a, int *len_b);
int			count_arg(char **s);
int			*alloc_fill2(int *array, char **s, int n_int);
int			choose_count(int n_argc, char **s);
int			*choose_alloc(int *array, char **s, int n_int, int n_argc);

#endif
