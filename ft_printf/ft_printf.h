/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 10:19:19 by raissaou          #+#    #+#             */
/*   Updated: 2025-01-13 10:19:19 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *str, ...);
int			ft_printf_character(int c);
int			ft_printf_string(char *str);
int			ft_printf_number(int nb);
int			ft_printf_unsigned(unsigned int nb);
int			ft_printf_hexadecimal(unsigned int nb, char *base);
int			ft_printf_pointer(unsigned long long ptr);

#endif