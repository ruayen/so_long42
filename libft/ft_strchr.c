/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 11:13:40 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-03 11:13:40 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
    const char *str = "Hello World";
    char c = 'W';

    char *result = ft_strchr(str, c);

    if (result != NULL) {
        printf("The character '%c' is in position %ld\n", c, result - str);
    } else {
        printf("The character '%c' is not found in the string.\n", c);
    }

    return 0;
}*/