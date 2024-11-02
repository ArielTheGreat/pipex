/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:38:08 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:38:22 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;
	size_t	counter2;
	size_t	ocurrence_int;

	counter = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (counter < len && haystack[counter] != '\0')
	{
		if (haystack[counter] == *needle)
		{
			counter2 = 0;
			ocurrence_int = counter;
			while (haystack[ocurrence_int] == needle[counter2]
				&& needle[counter2] != '\0' && ocurrence_int < len)
			{
				ocurrence_int++;
				counter2++;
			}
			if (needle[counter2] == '\0')
				return ((char *)haystack + counter);
		}
		counter++;
	}
	return (NULL);
}
