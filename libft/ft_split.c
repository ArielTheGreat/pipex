/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:56:05 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:56:24 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	calculate_delimiters_in_str(char const *s, char character_delimiter)
{
	int	counter;
	int	counter2;
	int	flag;

	counter = 0;
	counter2 = 0;
	flag = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] != character_delimiter)
			flag = 1;
		else
		{
			if (flag == 1)
				counter2++;
			flag = 0;
		}
		counter++;
	}
	if (flag == 1)
		counter2++;
	return (counter2);
}

char	*create_string(int start, char const *s, char delimiter)
{
	int		len;
	int		i;
	char	*str_space;

	len = 0;
	while (s[start + len] && s[start + len] != delimiter)
		len++;
	str_space = (char *)malloc((len + 1) * sizeof(char));
	if (!str_space)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str_space[i] = s[start + i];
		i++;
	}
	str_space[i] = '\0';
	return (str_space);
}

void	free_strings(char **strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

int	process_split(char **strings, const char *s, char delimiter)
{
	int	counter;
	int	counter3;

	counter = 0;
	counter3 = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] != delimiter)
		{
			strings[counter3] = create_string(counter, s, delimiter);
			if (!strings[counter3])
			{
				free_strings(strings, counter3);
				return (-1);
			}
			counter3++;
			while (s[counter] && s[counter] != delimiter)
				counter++;
		}
		if (s[counter] != '\0')
			counter++;
	}
	strings[counter3] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = malloc((calculate_delimiters_in_str(s, c) + 2) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	if (process_split(strings, s, c) == -1)
		return (NULL);
	return (strings);
}
