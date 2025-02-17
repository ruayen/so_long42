/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-04 11:38:24 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-04 11:38:24 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
    const char *str = "Hello World";
    int c = 'W';

    char *result = ft_memchr(str, c, 10);

    if (result != NULL) {
        printf("The character '%c' is in position %ld\n", c, result - str);
    } else {
        printf("The character '%c' is not found in the string.\n", c);
    }

    return 0;
}*/