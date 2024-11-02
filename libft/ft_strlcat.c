/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:14:01 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:14:36 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	counter;
	size_t	counter2;
	size_t	counter3;

	counter = 0;
	while (dst[counter] != '\0' & counter < dstsize)
		counter++;
	counter2 = ft_strlen(src);
	if (dstsize == 0)
		return (counter2);
	counter3 = (counter2 + counter);
	counter2 = 0;
	while (src[counter2] != '\0' && counter < (dstsize - 1))
	{
		dst[counter] = src[counter2];
		counter++;
		counter2++;
	}
	if (counter < dstsize)
		dst[counter] = '\0';
	return (counter3);
}
