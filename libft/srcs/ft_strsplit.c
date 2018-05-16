/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:55:23 by sshiling          #+#    #+#             */
/*   Updated: 2017/11/03 12:46:40 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_counter(char const *str, char c)
{
	int		i;
	int		indicator;
	int		words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		indicator = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			indicator = 1;
			i++;
		}
		while (str[i] == c && str[i] != '\0')
			i++;
		if (indicator == 1)
			words++;
	}
	return (words);
}

static int	new_str_size(char const *str, char c)
{
	int		i;

	i = 0;
	while (str[i] == c && str[i] != '\0')
		str++;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static char	**mk_split(char **array, char const *s, char c, int words_counter)
{
	char	*new_str;
	int		key;
	int		i;

	i = 0;
	key = 0;
	while (key < words_counter)
	{
		new_str = (char*)malloc(sizeof(char) * (new_str_size(s, c) + 1));
		if (new_str == NULL)
			return (NULL);
		while (s[0] == c && s[0] != '\0')
			s++;
		while (s[0] != c && s[0] != '\0')
			new_str[i++] = *s++;
		new_str[i] = '\0';
		array[key++] = new_str;
		i = 0;
	}
	array[words_counter] = 0;
	return (array);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words_counter;
	char	**array;

	if (s == NULL)
		return (NULL);
	words_counter = ft_words_counter(s, c);
	array = (char**)malloc(sizeof(char*) * (words_counter + 1));
	if (array == NULL)
		return (NULL);
	array = mk_split(array, s, c, words_counter);
	return (array);
}
