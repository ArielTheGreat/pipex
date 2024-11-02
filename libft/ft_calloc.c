/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:44:31 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:44:48 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*initialized_mem;
	size_t	counter;

	if (count == 0 || size == 0)
		return (malloc(1));
	initialized_mem = malloc(count * size);
	if (initialized_mem == NULL)
	{
		return (NULL);
	}
	counter = 0;
	while (counter < (count * size))
	{
		*((unsigned char *)initialized_mem + counter) = 0;
		counter++;
	}
	return (initialized_mem);
}
