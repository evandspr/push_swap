/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesprez <edesprez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:04:24 by edesprez          #+#    #+#             */
/*   Updated: 2024/11/28 12:55:00 by edesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(char *s, char c)
{
	int	i;
	int	nb_mots;

	i = 0;
	nb_mots = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && (size_t)i != ft_strlen(s) - 1)
			nb_mots++;
		i++;
	}
	if (s[0] != c && ft_strlen(s) != 0)
		return (nb_mots + 1);
	return (nb_mots);
}

static char	**free_array(char **s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

static char	*extract_word(char const *s, char c, int *i)
{
	int		start;
	int		len;
	char	*word;

	while ((s[*i] == c) && s[*i])
		(*i)++;
	start = *i;
	len = 0;
	while (s[*i] && (s[*i] != c))
	{
		(*i)++;
		len++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	ft_strlcpy(word, &s[start], len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_words;
	int		nb_words;
	int		i;
	int		k;

	if (!s)
		return (0);
	nb_words = count_words((char *)s, c);
	tab_words = malloc(sizeof(char *) * (nb_words + 1));
	if (!tab_words)
		return (0);
	i = 0;
	k = 0;
	while (k < nb_words)
	{
		tab_words[k] = extract_word(s, c, &i);
		if (!tab_words[k++])
			return (free_array(tab_words, k - 1));
	}
	tab_words[k] = NULL;
	return (tab_words);
}
/*#include <stdio.h>
int	main(void)
{
	char	**tab;
	char	*string = "hello!";
	tab = ft_split(string, ' ');
	int	i = 0;
	while(tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
}*/
