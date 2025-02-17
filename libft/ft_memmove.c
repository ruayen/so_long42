/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 09:38:50 by raissaou          #+#    #+#             */
/*   Updated: 2024-12-03 09:38:50 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*#include <stdio.h>
int main() {
    char src1[] = "Hello Rayane10";
    char dest1[20];
    char src2[] = "123456789";
    char *dest2 = src2 + 4;

    // Case 1: No overlap
    ft_memmove(dest1, src1, ft_strlen(src1) + 1);
    printf("Case 1: %s\n", dest1);

    // Case 2: Overlap
    printf("Case 2 before: %s\n", src2);
    ft_memmove(dest2, src2, 5);
    printf("Case 2 after: %s\n", src2);

    // Case 3: NULL src and dest
    char *result = ft_memmove(NULL, NULL, 5);
    printf("Case 3: %s\n", result == NULL ? "NULL" : "Error");

    return 0;
	*/