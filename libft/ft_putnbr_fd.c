/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:07:02 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 23:07:21 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	exponential_ten(int exponent)
{
	int	counter;
	int	base;

	counter = 0;
	base = 1;
	while (counter < exponent)
	{
		base = base * 10;
		counter++;
	}
	return (base);
}

int	length_int(int num)
{
	int	counter;

	counter = 0;
	while (num > 9)
	{
		num = num / 10;
		counter++;
	}
	return (counter + 1);
}

int	handle_n(int n, int fd)
{
	char	character;

	if (n < 0)
	{
		n *= -1;
		character = '-';
		write(fd, &character, 1);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		number;
	char	character;
	int		length_number;
	int		divisor;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		n = handle_n(n, fd);
		number = n;
		length_number = length_int(number);
		while (length_number > 0)
		{
			divisor = exponential_ten(length_number - 1);
			number = n / divisor;
			character = number + '0';
			write(fd, &character, 1);
			n -= number * divisor;
			length_number--;
		}
	}
}
