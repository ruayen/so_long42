/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:19:24 by raissaou          #+#    #+#             */
/*   Updated: 2025-01-14 09:19:24 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenght_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static void	ft_search_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_search_pointer(ptr / 16);
		ft_search_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_printf_character(ptr + '0');
		else
			ft_printf_character(ptr - 10 + 'a');
	}
}

int	ft_printf_pointer(unsigned long long ptr)
{
	int		size;

	size = 0;
	if (ptr == 0)
		size += ft_printf_string("(nil)");
	else
	{
		size += ft_printf_string("0x");
		ft_search_pointer(ptr);
		size += ft_lenght_pointer(ptr);
	}
	return (size);
}
