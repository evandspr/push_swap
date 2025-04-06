/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:06:17 by edesprez          #+#    #+#             */
/*   Updated: 2024/11/19 13:47:17 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *verif)
{
	int	retval;
	int	negative;
	int	i;

	retval = 0;
	negative = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		retval = retval * 10 + (str[i++] - '0');
	if ((str[i - 1] - '0') != (retval % 10))
		*verif = 0;
	retval = retval * negative;
	return (retval);
}

/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	(void)argc;
	int	i;

	i = 1;
	printf("%d", ft_atoi(argv[1], &i));
	printf("\n%d", i);
}*/
