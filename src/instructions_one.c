/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:42:53 by edesprez          #+#    #+#             */
/*   Updated: 2025/03/14 14:48:55 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_pile *pile)
{
	int	swp;

	swp = 0;
	if (pile->sizea >= 2)
	{
		swp = pile->pilea[0];
		pile->pilea[0] = pile->pilea[1];
		pile->pilea[1] = swp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_pile *pile)
{
	int	swp;

	swp = 0;
	if (pile->sizeb >= 2)
	{
		swp = pile->pileb[0];
		pile->pileb[0] = pile->pileb[1];
		pile->pileb[1] = swp;
		write(1, "sb\n", 3);
	}
}

void	pa(t_pile *pile)
{
	int	i;

	if (pile->sizeb > 0)
	{
		pile->sizea += 1;
		i = pile->sizea - 1;
		while (i > 0)
		{
			pile->pilea[i] = pile->pilea[i - 1];
			i--;
		}
		pile->pilea[0] = pile->pileb[0];
		pile->sizeb -= 1;
		while (i < pile->sizeb)
		{
			pile->pileb[i] = pile->pileb[i + 1];
			i++;
		}
		write(1, "pa\n", 3);
	}
}

void	pb(t_pile *pile)
{
	int	i;

	if (pile->sizea > 0)
	{
		pile->sizeb += 1;
		i = pile->sizeb;
		while (i > 0)
		{
			pile->pileb[i] = pile->pileb[i - 1];
			i--;
		}
		pile->pileb[0] = pile->pilea[0];
		pile->sizea -= 1;
		while (i < pile->sizea)
		{
			pile->pilea[i] = pile->pilea[i + 1];
			i++;
		}
		write(1, "pb\n", 3);
	}
}

void	ss(t_pile *pile)
{
	sa(pile);
	sb(pile);
	write(1, "ss\n", 3);
}
