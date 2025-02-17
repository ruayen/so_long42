/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 14:06:33 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-13 14:06:33 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	digits(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*zero(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*convertion(int n, int len, int negative)
{
	char			*str;
	unsigned int	num;

	if (n < 0)
		num = -n;
	else
		num = n;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (negative)
	{
		str[0] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int				len;
	int				negative;

	negative = 0;
	if (n == 0)
		return (zero());
	if (n < 0)
		negative = 1;
	len = digits(n);
	return (convertion(n, len, negative));
}

/*#include <stdio.h>

int main() {
    int number = -2147483648;  
    char *str = ft_itoa(number);
    if (str != NULL) {
        printf("YES it worked %s\n", str);
        free(str);  
    } else {
        printf("Error\n");
    }

    return 0;
}*/
