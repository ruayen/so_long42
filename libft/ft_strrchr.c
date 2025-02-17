/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 11:36:37 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-03 11:36:37 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		i;

	i = 0;
	last = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last = ((char *) &s[i]);
		i++;
	}
	if ((char) c == s[i])
		last = ((char *)&s[i]);
	return (last);
}

/*
#include <stdio.h>
int main()
{
    const char *str = "olo";
    char c = 'o';

    char *result = ft_strrchr(str, c);

    if (result != NULL) {
        printf("The character '%c' is in position %ld\n", c, result - str);
    } else {
        printf("The character '%c' is not found in the string.\n", c);
    }

    return 0;
}*/