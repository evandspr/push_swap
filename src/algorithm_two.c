/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:25:43 by edesprez          #+#    #+#             */
/*   Updated: 2025/03/28 15:27:58 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	*bubble_sort(int *tab, t_pile *pile)
{
	int	i;
	int	j;

	if (!tab)
		return (0);
	j = 0;
	i = 0;
	while (i < pile->sizea)
	{
		while (j < pile->sizea - 1)
		{
			if (tab[j] > tab[j + 1])
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
		j = 0;
	}
	return (tab);
}

int	*give_rank(t_pile *pile, int *copy_pile)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < pile->sizea)
	{
		while (j < pile->sizea)
		{
			if (pile->pilea[i] == copy_pile[j])
			{
				pile->pilea[i] = j;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (pile->pilea);
}

int	*sort_for_radix(t_pile *pile)
{
	int	*copy_pile;
	int	i;

	i = 0;
	copy_pile = malloc(sizeof(int) * pile->sizea);
	if (!copy_pile)
		return (0);
	while (i < pile->sizea)
	{
		copy_pile[i] = pile->pilea[i];
		i++;
	}
	copy_pile = bubble_sort(copy_pile, pile);
	copy_pile = give_rank(pile, copy_pile);
	return (copy_pile);
}

int	nb_iterations(t_pile *pile)
{
	int	i;
	int	max;

	if (!pile)
		return (0);
	i = 0;
	max = pile->size_max;
	while (max > 0)
	{
		max = max / 2;
		i++;
	}
	return (i);
}
