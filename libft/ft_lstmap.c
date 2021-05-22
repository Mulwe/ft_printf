/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joctopus <joctopus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:42:03 by joctopus          #+#    #+#             */
/*   Updated: 2021/04/26 16:52:20 by joctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
 * ? lst - adress of pointer to an element;
 * ? void *(*f)(void *) - adress of function used to iterate on the list; 
 * ? void (*del)(void *) - function used to delete the content of 
 * ? an element if needed;
 * 
 ** return value: New list. NULL if allocation fails
 * 
 * Iterates the list ’lst’ and applies the function
 * ’f’ to the content of each element. Creates a new
 * list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to
 * delete the content of an element if needed.
 **/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*work;

	if (lst != NULL && f != NULL)
	{
		begin = ft_lstnew(f(lst->content));
		work = begin;
		while (lst->next)
		{
			lst = lst->next;
			work->next = ft_lstnew(ft_strdup(f(lst->content)));
			if (work == NULL)
			{
				ft_lstclear(&begin, del);
				return (NULL);
			}
			work = work->next;
		}
		return (begin);
	}
	return (NULL);
}
