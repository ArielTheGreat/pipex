/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:56:39 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:56:41 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	get_length_str(int number)
{
	int	counter;
	int	num;

	counter = 0;
	num = number;
	if (number < 0)
	{
		num = num * -1;
		counter++;
	}
	else if (number == 0)
	{
		counter++;
	}
	while (num != 0)
	{
		num = num / 10;
		counter++;
	}
	return (counter);
}

char	*handle_case_min(void)
{
	char	*str;

	str = (char *)malloc(12 * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

char	*ft_itoa(int n)
{
	int		counter;
	char	*str;
	int		number;

	if (n == -2147483648)
		return (handle_case_min());
	counter = get_length_str(n);
	str = (char *)malloc((counter + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[counter] = '\0';
	number = n;
	counter--;
	if (n < 0)
		number = -number;
	while (number >= 10)
	{
		str[counter] = (number % 10) + '0';
		counter--;
		number = number / 10;
	}
	str[counter] = number + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
