/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 10:15:12 by raissaou          #+#    #+#             */
/*   Updated: 2025-01-13 10:15:12 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_selection_format(va_list argument, const char word)
{
	int	size;

	size = 0;
	if (word == 'c')
		size += ft_printf_character(va_arg(argument, int));
	else if (word == 's')
		size += ft_printf_string((char *) va_arg(argument, unsigned char *));
	else if (word == 'p')
		size += ft_printf_pointer(va_arg(argument, unsigned long long));
	else if (word == 'd' || word == 'i')
		size += ft_printf_number(va_arg(argument, int));
	else if (word == 'u')
		size += ft_printf_unsigned(va_arg(argument, unsigned int));
	else if (word == 'x')
		size += ft_printf_hexadecimal(va_arg(argument, unsigned int),
				"0123456789abcdef");
	else if (word == 'X')
		size += ft_printf_hexadecimal(va_arg(argument, unsigned int),
				"0123456789ABCDEF");
	else if (word == '%')
		size += ft_printf_character('%');
	else
		size += ft_printf_character(word);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	argument;

	i = 0;
	size = 0;
	va_start(argument, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			size += ft_selection_format(argument, str[i + 1]);
			i++;
		}
		else
			size += ft_printf_character(str[i]);
		i++;
	}
	va_end(argument);
	return (size);
}

/*#include <stdio.h>

#include <limits.h>
int main()
{
	printf(" %ld ", LONG_MAX);
	printf("\n");
	ft_printf(" hola que tal %p ", LONG_MAX);
	
}*/