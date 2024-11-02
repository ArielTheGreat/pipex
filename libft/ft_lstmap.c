/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:18:29 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 23:18:31 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final_list;
	t_list	*first_element;
	t_list	*previous_successful_element;

	first_element = NULL;
	while (lst != NULL)
	{
		if (f(lst->content) != NULL)
		{
			final_list = ft_lstnew(f(lst->content));
			if (final_list == NULL)
			{
				ft_lstclear(&first_element, del);
				return (NULL);
			}
			if (first_element == NULL)
				first_element = final_list;
			else
				previous_successful_element->next = final_list;
			previous_successful_element = final_list;
		}
		lst = lst->next;
	}
	return (first_element);
}
