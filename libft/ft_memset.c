/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 08:28:35 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-03 08:28:35 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	while (n > 0)
	{
		*ss = (unsigned char)c;
		ss++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>
int main() 
{
    char arr[10];
    int i = 0;
    
    ft_memset(arr, 'A', 10);
    
    while (i < 10) {
        printf("%c ", arr[i]);
        i++; 
    }
}*/
