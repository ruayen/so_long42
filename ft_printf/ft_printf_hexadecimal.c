/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 10:21:57 by raissaou          #+#    #+#             */
/*   Updated: 2025-01-14 10:21:57 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexadecimal(unsigned int nb, char *base)
{
	int		size;
	int		i;
	int		result_base[16];

	size = 0;
	i = 0;
	if (nb == 0)
		size += ft_printf_character('0');
	else
	{
		while (nb > 0)
		{
			result_base[i] = nb % 16;
			nb /= 16;
			i++;
		}
	}
	while (--i >= 0)
		size += ft_printf_character(base[result_base[i]]);
	return (size);
}
