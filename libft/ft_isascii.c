/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:45:48 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 21:45:53 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int character_number)
{
	if (character_number >= 0 && character_number <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
