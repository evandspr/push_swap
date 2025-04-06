/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:16:21 by edesprez          #+#    #+#             */
/*   Updated: 2025/02/25 11:16:23 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Checking if there is any duplicates

int	check_doublon(int argc, char **argv)
{
	int	i;
	int	j;
	int	verif;

	i = 0;
	j = 0;
	verif = 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (j + 1 >= argc)
			{
				i++;
				j = i;
			}
			if (i + 1 >= argc)
				return (1);
			if (ft_atoi(argv[i], &verif) == ft_atoi(argv[j + 1], &verif))
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_condition(int argc, char **argv)
{
	int	i;
	int	j;
	int	verif;

	i = 0;
	verif = 1;
	if (argc < 1 || !(check_doublon(argc, argv)))
		return (0);
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		ft_atoi(argv[i], &verif);
		if (!verif)
			return (0);
		i++;
	}
	return (1);
}

int	count_args(char **argv)
{
	int	count;

	count = 0;
	if (!argv)
		return (0);
	while (argv[count])
		count++;
	return (count);
}

int	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
