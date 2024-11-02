/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:15:47 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 23:15:49 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*temporal;

	counter = 0;
	temporal = lst;
	while (temporal != NULL)
	{
		counter++;
		temporal = temporal->next;
	}
	return (counter);
}
