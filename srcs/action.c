/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:10:32 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/12 17:57:53 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push_b(t_data *data)
{
	t_stack *temp;

	if(!data->stack_a)
		return ;
	temp = data->stack_a->next;
	data->stack_a->next = data->stack_b;
	data->stack_b = data->stack_a;
	data->stack_a = temp;
	ft_printf("pb\n");
}

void	ft_push_a(t_data *data)
{
	t_stack *temp;
	if(!data->stack_b)
		return ;
	temp = data->stack_b->next;
	data->stack_b->next = data->stack_a;
	data->stack_a = data->stack_b;
	data->stack_b = temp;
	ft_printf("pa\n");
}

t_stack	*ft_stackswap(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	if(ft_stacksize(stack) < 2)
		return (stack);
	temp = stack->next;
	stack->next = stack->next->next;
	temp->next = stack;
	stack = temp;

	return (stack);
}

t_stack	*ft_rotstack(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while(stack->next != NULL)
	{
		stack = stack->next;
	}
	stack->next = temp;
	stack = temp->next;
	temp->next = NULL;
	return (stack);
}

t_stack *ft_rrotstack(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while(stack->next->next != NULL)
	{
		stack = stack->next;
	}
	stack->next->next = temp;
	temp = stack->next;
	stack->next = NULL;
	stack = temp;

	return (stack);	
}

