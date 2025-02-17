/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:34:07 by raissaou          #+#    #+#             */
/*   Updated: 2024/12/02 15:50:08 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int main()
{
    int c = '5';  // ASCII for the digit '5'

    printf("Is '%c' a digit? %d\n", c, ft_isdigit(c));

    c = 'A';  // Not a digit
    printf("Is '%c' a digit? %d\n", c, ft_isdigit(c));

    c = '0';  // ASCII for the digit '0'
    printf("Is '%c' a digit? %d\n", c, ft_isdigit(c));

    return 0;
}*/