/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:18:33 by edesprez          #+#    #+#             */
/*   Updated: 2025/03/18 15:18:36 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_pile *pile)
{
	int	i;
	int	tmp;

	i = 0;
	if (pile->sizea > 0)
	{
		tmp = pile->pilea[0];
		while (i < pile->sizea - 1)
		{
			pile->pilea[i] = pile->pilea[i + 1];
			i++;
		}
		pile->pilea[i] = tmp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_pile *pile)
{
	int	i;
	int	tmp;

	i = 0;
	if (pile->sizeb > 0)
	{
		tmp = pile->pileb[0];
		while (i < pile->sizeb - 1)
		{
			pile->pileb[i] = pile->pileb[i + 1];
			i++;
		}
		pile->pileb[i] = tmp;
		write(1, "rb\n", 3);
	}
}

void	rr(t_pile *pile)
{
	ra(pile);
	rb(pile);
	write(1, "rr\n", 3);
}

void	rra(t_pile *pile)
{
	int	tmp;
	int	i;

	if (pile->sizea > 0)
	{
		i = pile->sizea - 1;
		tmp = pile->pilea[i];
		while (i > 0)
		{
			pile->pilea[i] = pile->pilea[i - 1];
			i--;
		}
		pile->pilea[0] = tmp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_pile *pile)
{
	int	tmp;
	int	i;

	if (pile->sizeb > 0)
	{
		i = pile->sizeb - 1;
		tmp = pile->pileb[i];
		while (i >= 0)
		{
			pile->pileb[i] = pile->pileb[i - 1];
			i--;
		}
		pile->pileb[0] = tmp;
		write(1, "rrb\n", 4);
	}
}
