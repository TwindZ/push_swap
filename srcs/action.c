/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:10:32 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/24 15:46:06 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*This function pushes the top node of the stack "a" to the top of the 
stack "b".*/
void	ft_push_b(t_data *data)
{
	t_stack	*temp;

	if (!data->stack_a)
		return ;
	temp = data->stack_a->next;
	data->stack_a->next = data->stack_b;
	data->stack_b = data->stack_a;
	data->stack_a = temp;
	ft_write_or_count(data, "pb");
}

/*This function pushes the top node of the stack "b" to the top of the 
stack "a".*/
void	ft_push_a(t_data *data)
{
	t_stack	*temp;

	if (!data->stack_b)
		return ;
	temp = data->stack_b->next;
	data->stack_b->next = data->stack_a;
	data->stack_a = data->stack_b;
	data->stack_b = temp;
	ft_write_or_count(data, "pa");
}

/*This function swaps the first two elements of a stack passed 
as a parameter.*/
t_stack	*ft_stackswap(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	if (ft_stacksize(stack) < 2)
		return (stack);
	temp = stack->next;
	stack->next = stack->next->next;
	temp->next = stack;
	stack = temp;
	return (stack);
}

/*This function rotates the stack upwards, such that the 
first element becomes the last.*/
t_stack	*ft_rotstack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (stack->next != NULL)
		stack = stack->next;
	stack->next = temp;
	stack = temp->next;
	temp->next = NULL;
	return (stack);
}

/*This function rotates the stack downwards, such that the 
last element becomes the first.*/
t_stack	*ft_rrotstack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (stack->next->next != NULL)
		stack = stack->next;
	stack->next->next = temp;
	temp = stack->next;
	stack->next = NULL;
	stack = temp;
	return (stack);
}
