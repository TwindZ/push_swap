/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:21:06 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/17 16:55:55 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_printlist(t_stack *list)
{
	while(list != NULL)
	{
		// ft_printf("\nlist :		%p \n", list);
		// ft_printf("\nlist->index : %d \n", list->index);
		// ft_printf("\nlist->content : %d \n\n", list->content);
		// ft_printf("list->next :	%p \n		|\n", list->next);
		ft_printf("%d\n", list->content);
		list = list->next;
		usleep(50000);
	}
}

t_stack	*ft_lstnew_int(int content)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->next = NULL;
	stack->index = 0;
	return (stack);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
