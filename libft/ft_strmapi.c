/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-16 10:23:19 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-16 10:23:19 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc((ft_strlen(s)+1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>

char my_func(unsigned int i, char c) {
    return c + i;  // Example: Modify character by adding its index
}
int main() {
    const char *s = "Hello";
    char *result = ft_strmapi(s, my_func);

    if (result) {
        printf("Result: %s\n", result);
        free(result);  // Don't forget to free the allocated memory
    } else {
        printf("Error allocating memory\n");
    }

    return 0;
}*/