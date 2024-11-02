/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:35:34 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:35:54 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	uc;

	counter = 0;
	uc = (unsigned char)c;
	while (counter < n)
	{
		if (uc == *((unsigned char *)s + counter))
			return ((void *)s + counter);
		counter++;
	}
	return (NULL);
}
