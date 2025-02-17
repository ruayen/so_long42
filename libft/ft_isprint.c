/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 08:03:19 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-03 08:03:19 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int main()
{
    int c = 65; 

    printf("Is '%c' printable? %d\n", c, ft_isprint(c));

    c = 9;  
    printf("Is '%c' printable? %d\n", c, ft_isprint(c));

    c = 32;  
    printf("Is '%c' printable? %d\n", c, ft_isprint(c));

    c = 127;  
    printf("Is '%c' printable? %d\n", c, ft_isprint(c));

    return 0;
}*/