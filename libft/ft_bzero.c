/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 08:47:33 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-03 08:47:33 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

/*#include <stdio.h>
int main()
{
    char str[11] = "Hello World";

    printf("Before ft_bzero: '%s'\n", str);

    ft_bzero(str, 5);

    printf("After ft_bzero: '%s'\n", str);

    return 0;
}*/
