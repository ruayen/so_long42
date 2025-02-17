/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:05:52 by marvin            #+#    #+#             */
/*   Updated: 2024/12/10 15:05:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long	i;
	int				j;

	j = 0;
	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i] == little[j] && big[i] && i < len)
		{
			i++;
			j++;
		}
		if (!little[j])
			return ((char *)&big[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}

/*#include <stdio.h>
int main() {
    const char *big = "Hello, test is a test string.";
    const char *little = "test";
    size_t len = 20;

    char *result = ft_strnstr(big, little, len);
    
    if (result) {
        printf("Found the substring: %s\n", result);
    } else {
        printf("Substring not found within the first %zu characters.\n", len);
    }

    return 0;
}*/