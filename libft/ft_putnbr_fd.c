/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-16 12:41:58 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-16 12:41:58 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	str[12];

	i = 0;
	if (n == 0)
		write (fd, "0", 1);
	else if (n < 0)
	{
		write (fd, "-", 1);
		if (n == -2147483648)
		{
			write (fd, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (--i >= 0)
		write (fd, &str[i], 1);
}

/*#include <fcntl.h>
#include "libft.h"

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        return 1;
    }
    ft_putnbr_fd('5', fd);
    close(fd);
    return 0;
}*/