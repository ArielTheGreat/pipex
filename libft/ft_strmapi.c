/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:58:25 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:58:30 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		counter;
	char	*str_space;

	counter = 0;
	while (*(s + counter) != '\0')
		counter++;
	str_space = (char *)malloc((counter + 1) * sizeof(char));
	if (str_space == NULL)
		return (NULL);
	counter = 0;
	while (*(s + counter) != '\0')
	{
		str_space[counter] = f(counter, s[counter]);
		counter++;
	}
	str_space[counter] = '\0';
	return (str_space);
}
