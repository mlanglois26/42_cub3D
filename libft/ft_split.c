/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrischma <hrischma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:32:50 by hrischma          #+#    #+#             */
/*   Updated: 2024/02/19 20:32:52 by hrischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	is_sep(char c, char sep)
{
	return (c == sep);
}

static unsigned int	word_count(const char *str, char sep)
{
	unsigned int	count;
	unsigned int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_sep(*str, sep) && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (is_sep(*str, sep))
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

static char	*alloc_word(const char *str, char sep)
{
	unsigned int	len;
	const char		*start;
	char			*word;
	unsigned int	i;

	len = 0;
	i = 0;
	start = str;
	while (str[len] && !is_sep(str[len], sep))
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static char	**split_into_words(const char *str, char sep,
			char **array, unsigned int word_nb)
{
	unsigned int	i;

	i = 0;
	while (i < word_nb)
	{
		while (*str && is_sep(*str, sep))
			str++;
		if (*str && !is_sep(*str, sep))
		{
			array[i] = alloc_word(str, sep);
			if (!array[i])
			{
				while (i > 0)
					free(array[--i]);
				free(array);
				return (NULL);
			}
			i++;
			while (*str && !is_sep(*str, sep))
				str++;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *str, char c)
{
	char			**array;
	unsigned int	word_nb;

	if (!str)
		return (NULL);
	word_nb = word_count(str, c);
	array = malloc((word_nb + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (split_into_words(str, c, array, word_nb));
}
