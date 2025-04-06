/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:37:24 by edesprez          #+#    #+#             */
/*   Updated: 2024/11/21 10:41:38 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	while (src[s])
		s++;
	while (src[i] && i < size - 1 && size > 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (s);
}

/*int   main(void)
{
	char *str = "aaa";
	char buff1[0xF00];
	char buff2[0xF00];
	//printf("%s\n", argv[1]);
	//printf("%s\n", argv[2]);
	printf("%s\n", "--------------------------");
	printf("%s\n", "MINE :");
	printf("%lu\n", ft_strlcpy(buff1, str, 0));
	printf("%s\n", "--------------------------");
	printf("%s\n", "ORIGINAL");
	printf("%zu\n", strlcpy(buff2, str, 0));
	//printf("%s\n", argv[1]);
	//printf("%s\n", argv[2]);
}*/
