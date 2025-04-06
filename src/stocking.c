/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:12:40 by edesprez          #+#    #+#             */
/*   Updated: 2025/03/12 19:12:53 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Stocking for argc = 2 (numbers between quotes)

int	*stocking1(int nb_nbr, char **argv, t_pile *pile)
{
	int		i;
	int		verif;
	int		*tab_nb;
	char	**tab;

	verif = 1;
	i = 0;
	tab = ft_split(argv[1], ' ');
	nb_nbr = count_args(tab);
	if (!(check_condition(nb_nbr, tab)))
	{
		write(2, "Error\n", 6);
		free_tab(tab);
		return (0);
	}
	tab_nb = malloc(sizeof(int) * nb_nbr);
	while (tab_nb && tab[i])
	{
		tab_nb[i] = ft_atoi(tab[i], &verif);
		free(tab[i++]);
	}
	free(tab);
	pile->size_max = nb_nbr;
	return (tab_nb);
}

int	*stocking2(int argc, char **argv, t_pile *pile)
{
	int	i;
	int	*tab_nb;
	int	verif;

	i = 0;
	verif = 1;
	if (!(check_condition(argc - 1, argv + 1)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	tab_nb = malloc(sizeof(int) * (argc - 1));
	if (!tab_nb)
		return (0);
	while (i < argc - 1)
	{
		tab_nb[i] = ft_atoi(argv[i + 1], &verif);
		i++;
	}
	pile->size_max = argc - 1;
	return (tab_nb);
}

int	*stocking(int argc, char **argv, t_pile *pile)
{
	int	nb_nbr;

	nb_nbr = count_args(argv);
	if (argc < 2)
		return (0);
	if (argc == 2)
		return (stocking1(nb_nbr, argv, pile));
	if (argc > 2)
		return (stocking2(nb_nbr, argv, pile));
	return (0);
}
