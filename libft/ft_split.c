/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 13:55:32 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-13 13:55:32 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(char const *str, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str != '\0')
	{
		if (*str == delimiter)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	**free_memory(char **result, int words)
{
	while (words > 0)
	{
		words--;
		free(result[words]);
	}
	free(result);
	return (NULL);
}

static char	*allocate_word(char const *str, char delimiter, int *index)
{
	int		len;
	int		start;
	char	*word;
	int		i;

	start = *index;
	len = 0;
	while (str[start] != delimiter && str[start] != '\0')
	{
		len++;
		start++;
	}
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (str[*index] != '\0' && str[*index] != delimiter)
	{
		word[i++] = str[(*index)++];
	}
	word[i] = '\0';
	return (word);
}

static char	**assign_words(char const *str, char **result,
	char delimiter, int total_words)
{
	int	i;
	int	word_index;

	i = 0;
	word_index = 0;
	while (str[i] != '\0' && word_index < total_words)
	{
		while (str[i] == delimiter)
			i++;
		result[word_index] = allocate_word(str, delimiter, &i);
		if (!result[word_index])
			return (free_memory(result, word_index));
		word_index++;
	}
	result[word_index] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		total_words;

	if (!s)
		return (NULL);
	total_words = count_words(s, c);
	result = (char **)malloc((total_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (assign_words(s, result, c, total_words));
}

/*
#include <stdio.h>
int main() {
    char *string = "Hello-world this is a test";
    char **split_result = ft_split(string, '-');

    if (split_result != NULL) {
        for (int i = 0; split_result[i] != NULL; i++) {
            printf("Word %d: %s\n", i, split_result[i]);
            free(split_result[i]);  
        }
        free(split_result);
    }
	else
	{
		        printf("Error\n");
	}

    return 0;
}*/
