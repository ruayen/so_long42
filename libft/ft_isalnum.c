/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:39:00 by raissaou          #+#    #+#             */
/*   Updated: 2024/12/02 15:48:29 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int main()
{
    char c = 'A';

    printf("Is '%c' alphanumeric? %d\n", c, ft_isalnum(c));

    c = '1';
    printf("Is '%c' alphanumeric? %d\n", c, ft_isalnum(c));

    c = '#';
    printf("Is '%c' alphanumeric? %d\n", c, ft_isalnum(c));

    return 0;
}*/
