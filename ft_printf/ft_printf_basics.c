/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 11:01:40 by raissaou          #+#    #+#             */
/*   Updated: 2025-01-13 11:01:40 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_character(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_string(char *str)
{
	int	size;

	size = 0;
	if (str == 0)
		size += write(1, "(null)", 6);
	else
	{
		while (str[size] != '\0')
			size += ft_printf_character(str[size]);
	}
	return (size);
}

int	ft_printf_number(int nb)
{
	int		size;

	size = 0;
	if (nb == 0)
		return (ft_printf_character('0'));
	if (nb < 0)
	{
		size += ft_printf_character('-');
		if (nb == -2147483648)
		{
			size += ft_printf_string("2147483648");
			return (size);
		}
		nb = -nb;
	}
	if (nb > 0)
		size += ft_printf_unsigned((unsigned int) nb);
	return (size);
}

int	ft_printf_unsigned(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		size += ft_printf_character('0');
	else
	{
		if (nb > 9)
			ft_printf_unsigned(nb / 10);
		ft_printf_character((nb % 10) + '0');
		while (nb > 0)
		{
			nb /= 10;
			size++;
		}
	}
	return (size);
}
