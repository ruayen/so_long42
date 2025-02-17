/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:09:53 by marvin            #+#    #+#             */
/*   Updated: 2024/12/12 11:09:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a;
	int		b;
	char	*str;

	i = 0;
	j = 0;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = malloc((a + b + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
int main() {
 char *str1 = "Hello ";
 char *str2 = "world";
 char *result = ft_strjoin(str1, str2);
 if (result != NULL) {
 printf("RESULT: %s\n", result);
 } else {
 printf("Error.\n");
 }
 return 0;
}*/