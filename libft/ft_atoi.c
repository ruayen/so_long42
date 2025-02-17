/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-18 12:17:40 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-18 12:17:40 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

/*
#include <stdio.h>
int main()
{
    
    const char *nptr1 = "12345";
    const char *nptr2 = "-98a76";
    const char *nptr3 = "   42";
    const char *nptr4 = "+67";
    const char *nptr5 = "   -2147483648"; 

    printf("ft_atoi(\"%s\") = %d\n", nptr1, ft_atoi(nptr1));
    printf("ft_atoi(\"%s\") = %d\n", nptr2, ft_atoi(nptr2));
    printf("ft_atoi(\"%s\") = %d\n", nptr3, ft_atoi(nptr3));
    printf("ft_atoi(\"%s\") = %d\n", nptr4, ft_atoi(nptr4));
    printf("ft_atoi(\"%s\") = %d\n", nptr5, ft_atoi(nptr5));

    return 0;
}*/
