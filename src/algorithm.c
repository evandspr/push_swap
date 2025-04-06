/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:15:38 by edesprez          #+#    #+#             */
/*   Updated: 2025/04/05 22:17:42 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_pile *pile)
{
	int	i;

	i = 0;
	if (!pile)
		return (0);
	while (i + 1 < pile->sizea)
	{
		if (pile->pilea[i] > pile->pilea[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

void	only_two(t_pile *pile)
{
	if (pile->pilea[0] > pile->pilea[1])
		sa(pile);
}

void	only_three(t_pile *pile)
{
	while (!is_sorted(pile))
	{
		if (pile->pilea[0] > pile->pilea[1] && pile->pilea[1] < pile->pilea[2]
			&& pile->pilea[0] < pile->pilea[2])
			sa(pile);
		else if (pile->pilea[0] < pile->pilea[1]
			&& pile->pilea[1] > pile->pilea[2]
			&& pile->pilea[0] > pile->pilea[2])
			rra(pile);
		else if (pile->pilea[0] > pile->pilea[1]
			&& pile->pilea[1] < pile->pilea[2])
			ra(pile);
		else if (pile->pilea[0] < pile->pilea[1]
			&& pile->pilea[1] > pile->pilea[2])
		{
			sa(pile);
			ra(pile);
		}
		else
		{
			ra(pile);
			sa(pile);
		}
	}
}

void	only_four(t_pile *pile)
{
	while (!(pile->pilea[0] < pile->pilea[1]
			&& pile->pilea[0] < pile->pilea[2]
			&& pile->pilea[0] < pile->pilea[3]))
		ra(pile);
	if (!is_sorted(pile))
	{
		pb(pile);
		only_three(pile);
		pa(pile);
	}
}

void	only_five(t_pile *pile)
{
	only_two(pile);
	while (!(pile->pilea[0] < pile->pilea[1]
			&& pile->pilea[0] < pile->pilea[2]
			&& pile->pilea[0] < pile->pilea[3]
			&& pile->pilea[0] < pile->pilea[4]))
		rra(pile);
	if (!is_sorted(pile))
	{
		pb(pile);
		only_four(pile);
		pa(pile);
	}
}
