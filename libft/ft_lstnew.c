/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:15:12 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 23:15:16 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p_new_node;

	p_new_node = (t_list *)malloc(sizeof(t_list));
	if (p_new_node == NULL)
		return (NULL);
	p_new_node->content = content;
	p_new_node->next = NULL;
	return (p_new_node);
}
