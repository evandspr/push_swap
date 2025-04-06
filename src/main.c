/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:29:37 by edesprez          #+#    #+#             */
/*   Updated: 2025/04/05 18:10:53 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_small_stack(t_pile *pile)
{
	if (pile->pilea && pile->sizea == 2)
		only_two(pile);
	else if (pile->pilea && pile->sizea == 3)
		only_three(pile);
	else if (pile->pilea && pile->sizea == 4)
		only_four(pile);
	else if (pile->pilea && pile->sizea == 5)
		only_five(pile);
}

void	radix_sort(t_pile *pile)
{
	int	nb_iter;
	int	i;
	int	j;

	nb_iter = nb_iterations(pile);
	i = 0;
	j = 0;
	while (nb_iter > 0)
	{
		while (i < pile->sizea)
		{
			if (((pile->pilea[0] >> j) & 1) == 0)
				pb(pile);
			else
			{
				ra(pile);
				i++;
			}
		}
		while (pile->sizeb > 0)
			pa(pile);
		j++;
		i = 0;
		nb_iter--;
	}
}

int	main(int argc, char **argv)
{
	t_pile	pile;

	if (argc < 2)
		return (0);
	pile.pilea = stocking(argc, argv, &pile);
	if (!pile.pilea)
		return (0);
	pile.sizea = pile.size_max;
	pile.pileb = malloc(sizeof(int) * pile.sizea);
	if (!pile.pileb)
	{
		free(pile.pilea);
		return (0);
	}
	pile.sizeb = 0;
	if (pile.sizea <= 5)
		sort_small_stack(&pile);
	else
		radix_sort(&pile);
	free(pile.pilea);
	free(pile.pileb);
	return (0);
}
