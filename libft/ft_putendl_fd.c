/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:06:18 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 23:06:33 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		counter;
	char	newline;

	counter = 0;
	while (*(s + counter) != '\0')
	{
		write(fd, s + counter, 1);
		counter++;
	}
	newline = '\n';
	write(fd, &newline, 1);
}
