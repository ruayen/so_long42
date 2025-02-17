/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:06:43 by raissaou          #+#    #+#             */
/*   Updated: 2024/12/02 15:49:17 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int main()
{
    char c = 'A';

    printf("Is '%c' alpha? %d\n", c, ft_isalpha(c));

    c = '1';
    printf("Is '%c' alpha? %d\n", c, ft_isalpha(c));

    c = '#';
    printf("Is '%c' alpha? %d\n", c, ft_isalpha(c));

    return 0;
}*/