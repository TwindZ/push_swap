/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:20:43 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/12 18:09:03 by emlamoth         ###   ########.fr       */
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

void	ft_rot_kind(t_data *data, char set)
{
	
	if(set == 'a')
	{
		data->stack_a = ft_rotstack(data->stack_a);
		ft_printf("ra\n");
	}
	else if (set == 'b')
	{
		data->stack_b = ft_rotstack(data->stack_b);
		ft_printf("rb\n");
	}
	else if (set == 's')
	{
		data->stack_a = ft_rotstack(data->stack_a);
		data->stack_b = ft_rotstack(data->stack_b);
		ft_printf("rr\n");
	}
}

void	ft_rrot_kind(t_data *data, char set)
{
	
	if(set == 'a')
	{
		data->stack_a = ft_rrotstack(data->stack_a);
		ft_printf("rra\n");
	}
	else if (set == 'b')
	{
		data->stack_b = ft_rrotstack(data->stack_b);
		ft_printf("rrb\n");
		
	}
	else if (set == 's')
	{
		data->stack_a = ft_rrotstack(data->stack_a);
		data->stack_b = ft_rrotstack(data->stack_b);
		ft_printf("rrr\n");
	}
}

void	ft_swap_kind(t_data *data, char set)
{
	if(set == 'a')
	{
		data->stack_a = ft_stackswap(data->stack_a);
		ft_printf("sa\n");
	}
	else if (set == 'b')
	{
		data->stack_b = ft_stackswap(data->stack_b);
		ft_printf("sb\n");
	}
	else if ( set == 's')
	{
		data->stack_a = ft_stackswap(data->stack_a);
		data->stack_b = ft_stackswap(data->stack_b);
		ft_printf("ss\n");
	}
}