/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:45:17 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:45:20 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		counter;
	char	*str_dup;

	counter = ft_strlen(s1);
	counter++;
	str_dup = malloc(counter * sizeof(char));
	if (str_dup == NULL)
		return (NULL);
	counter = 0;
	while (s1[counter] != '\0')
	{
		str_dup[counter] = s1[counter];
		counter++;
	}
	str_dup[counter] = '\0';
	return (str_dup);
}
