/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:48:27 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:48:43 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	concatenate_strings(int counter, char const *str_origin, char *str_destiny)
{
	int	counter_char;
	int	counter2;

	counter_char = counter;
	counter2 = 0;
	while (*(str_origin + counter2) != '\0')
	{
		*(str_destiny + counter_char) = *(str_origin + counter2);
		counter_char++;
		counter2++;
	}
	return (counter_char);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_characters;
	char	*str_space;
	int		counter;

	total_characters = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_space = (char *)malloc(total_characters * sizeof(char));
	if (str_space == NULL)
		return (NULL);
	counter = concatenate_strings(0, s1, str_space);
	counter = concatenate_strings(counter, s2, str_space);
	str_space[counter] = '\0';
	return (str_space);
}
