/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 07:55:29 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-03 07:55:29 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int main()
{
    int c = 65; 

    printf("Is %d ASCII? %d\n", c, ft_isascii(c));

    c = 128;  
    printf("Is %d ASCII? %d\n", c, ft_isascii(c));

    c = -1; 
    printf("Is %d ASCII? %d\n", c, ft_isascii(c));

    return 0;
}*/