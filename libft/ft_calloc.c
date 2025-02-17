/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:07:09 by marvin            #+#    #+#             */
/*   Updated: 2024/12/10 15:07:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmeb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmeb * size);
	return (ptr);
}

/*#include <stdio.h>
int main() 
{ 
int *arr; 
arr = (int *)ft_calloc(5, sizeof(int)); 
if (!arr) 
{ 
printf("Memory allocation failed.\n"); 
return 1; 
} 
printf("First element: %d\n", arr[0]); 
free(arr); return 0; 
}*/
