/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:59:36 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 21:59:56 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			a;
	unsigned char	x;

	a = 0;
	x = (unsigned char)c;
	if (x < 0 || x > 255)
		x = 0;
	while (a < len)
	{
		*((unsigned char *)b + a) = x;
		a++;
	}
	return (b);
}
