/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:55:52 by edesprez          #+#    #+#             */
/*   Updated: 2025/03/05 14:50:44 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include "../libft/libft.h"

typedef struct s_pile
{
	int	*pilea;
	int	*pileb;
	int	sizea;
	int	sizeb;
	int	size_max;
}	t_pile;

int		check_doublon(int argc, char **argv);
int		check_condition(int argc, char **argv);
int		count_args(char **argv);
int		free_tab(char **tab);
int		*stocking1(int nb_nbr, char **argv, t_pile *pile);
int		*stocking2(int argc, char **argv, t_pile *pile);
int		*stocking(int argc, char **argv, t_pile *pile);
int		is_sorted(t_pile *pile);
int		*sort_for_radix(t_pile *pile);
int		*bubble_sort(int *tab, t_pile *pile);
int		*give_rank(t_pile *pile, int *copy_pile);
int		nb_iterations(t_pile *pile);
void	sa(t_pile *pile);
void	sb(t_pile *pile);
void	ss(t_pile *pile);
void	pa(t_pile *pile);
void	pb(t_pile *pile);
void	ra(t_pile *pile);
void	rb(t_pile *pile);
void	rb(t_pile *pile);
void	rr(t_pile *pile);
void	rra(t_pile *pile);
void	rrb(t_pile *pile);
void	rrr(t_pile *pile);
void	only_two(t_pile *pile);
void	only_three(t_pile *pile);
void	only_four(t_pile *pile);
void	only_five(t_pile *pile);
void	sort_small_stack(t_pile *pile);
void	swap(int *x, int *y);
void	print_array(int *tab, int size);
void	radix_sort(t_pile *pile);

#endif
