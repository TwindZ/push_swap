/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:50:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/24 13:01:17 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*This algorithm sorts three numbers in a stack.*/
void	ft_sort_3(t_data *data)
{
	t_stack	*temp;

	temp = data->stack_a;
	if (temp->index > temp->next->index
		&& temp->next->index > temp->next->next->index)
	{
		ft_rot(data, 'a');
		ft_swap(data, 'a');
	}
	else if (temp->index > temp->next->index
		&& temp->index > temp->next->next->index)
		ft_rot(data, 'a');
	else if (temp->index > temp->next->index)
		ft_swap(data, 'a');
	else if (temp->index < temp->next->index
		&& temp->index > temp->next->next->index)
		ft_rrot(data, 'a');
	else if (temp->index < temp->next->index
		&& temp->index < temp->next->next->index)
	{
		ft_swap(data, 'a');
		ft_rot(data, 'a');
	}
}

/*This algorithm sorts four numbers using two stacks.*/
void	ft_sort_4(t_data *data)
{
	int	small;

	small = ft_find_smallest(data, 'a');
	while (ft_stacksize(data->stack_a) > 3)
	{
		if (data->stack_a->index == small)
			ft_push_b(data);
		ft_rot(data, 'a');
	}
	if (ft_sorted(data->stack_a) == FALSE && ft_stacksize(data->stack_a) == 3)
		ft_sort_3(data);
	ft_push_a(data);
}

/*This algorithm sorts five numbers using two stacks.*/
void	ft_sort_5(t_data *data)
{
	int	small;
	int	big;

	big = ft_find_biggest(data, 'a');
	small = ft_find_smallest(data, 'a');
	while (ft_stacksize(data->stack_a) > 3)
	{
		if (data->stack_a->index == big || data->stack_a->index == small)
			ft_push_b(data);
		else
			ft_rot(data, 'a');
	}
	if (ft_sorted(data->stack_a) == FALSE && ft_stacksize(data->stack_a) == 3)
		ft_sort_3(data);
	ft_push_a(data);
	if (data->stack_a->index == small)
	{
		ft_push_a(data);
		ft_rot(data, 'a');
	}
	else if (data->stack_a->index == big)
	{
		ft_rot(data, 'a');
		ft_push_a(data);
	}
}

/*This algorithm sorts in the easiest way possible by finding the smallest
number one by one.*/
void	ft_simple_sort(t_data *data)
{
	while (data->stack_a != NULL && ft_sorted(data->stack_a) == FALSE)
	{
		if (data->stack_a->index == ft_find_smallest(data, 'a'))
			ft_push_b(data);
		else
			ft_rot(data, 'a');
	}
	while (data->stack_b != NULL)
		ft_push_a(data);
}
