/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:52:59 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:53:16 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	compare_trim(char character, char const *set)
{
	int	counter;

	counter = 0;
	while (*(set + counter) != '\0')
	{
		if (character == *(set + counter))
			return (1);
		counter++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		counter;
	int		counter2;
	int		counter3;
	char	*str_space;

	counter = 0;
	while (*(s1 + counter) != '\0')
		counter++;
	counter2 = 0;
	while (compare_trim(*(s1 + counter2), set) == 1 && *(s1 + counter2) != 0)
		counter2++;
	if (*(s1 + counter2) == '\0' || *s1 == '\0')
		return (ft_strdup(""));
	counter--;
	while (compare_trim(*(s1 + counter), set) == 1)
		counter--;
	str_space = (char *)malloc(((counter - counter2 + 1) + 1) * sizeof(char));
	if (str_space == NULL)
		return (NULL);
	counter3 = 0;
	while (counter2 <= counter)
		str_space[counter3++] = s1[counter2++];
	str_space[counter3] = '\0';
	return (str_space);
}
