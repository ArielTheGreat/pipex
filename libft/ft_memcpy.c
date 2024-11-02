/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:05:49 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:06:17 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	counter;

	counter = 0;
	if (!dst && !src)
		return (NULL);
	while (counter < n)
	{
		((char *) dst)[counter] = ((const char *) src)[counter];
		counter++;
	}
	return (dst);
}
