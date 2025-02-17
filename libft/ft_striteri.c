/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-16 11:00:37 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-16 11:00:37 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}

/*
#include <stdio.h>

void my_func(unsigned int i, char *c) {
    *c += i;  
}
int main() {
    char str[] = "Hello";

    printf("Before: %s\n", str);
    ft_striteri(str, my_func);
    printf("After: %s\n", str);

    return 0;
}
*/