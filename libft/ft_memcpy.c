/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 09:05:57 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-03 09:05:57 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

/*#include <stdio.h>
int main() {
    char src[] = "hello world";
    char dest[20];

    ft_memcpy(dest, src, 11);
    printf("Dest: %s\n", dest);
    
    return 0;
}*/