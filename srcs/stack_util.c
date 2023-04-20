/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:21:06 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/20 17:23:21 by emlamoth         ###   ########.fr       */
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

int	ft_find_biggest(t_data *data, char set)
{
	int		biggest;
	t_stack	*temp;

	biggest = INT_MIN;
	if (set == 'a')
		temp = data->stack_a;
	else
		temp = data->stack_b;
	while (temp != NULL)
	{
		if (biggest < temp->index)
			biggest = temp->index;
		temp = temp->next;
	}
	return (biggest);
}

int	ft_find_smallest(t_data *data, char set)
{
	int		smallest;
	t_stack	*temp;

	smallest = INT_MAX;
	if (set == 'a')
		temp = data->stack_a;
	else
		temp = data->stack_b;
	while (temp != NULL)
	{
		if (smallest > temp->index)
			smallest = temp->index;
		temp = temp->next;
	}
	return (smallest);
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
