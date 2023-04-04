/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:21:53 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/18 16:15:03 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*anew;
	void	*temp;

	if (!lst || !f)
		return (NULL);
	anew = NULL;
	while (lst)
	{
		temp = (f)(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			free(temp);
			ft_lstclear(&anew, del);
			break ;
		}
		ft_lstadd_back(&anew, new);
		lst = lst->next;
	}
	return (anew);
}
