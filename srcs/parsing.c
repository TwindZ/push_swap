/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:57:08 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/20 17:17:27 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->index + 1 != temp->next->index)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

int	ft_inverted_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->index - 1 != temp->next->index)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

int	ft_no_double(t_data *data)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = data->stack_a;
	if (temp != NULL)
		temp2 = data->stack_a->next;
	while (temp != NULL)
	{
		while (temp2 != NULL)
		{
			if (temp->content == temp2->content)
				return (FALSE);
			temp2 = temp2->next;
		}
		temp = temp->next;
		if (temp != NULL)
			temp2 = temp->next;
	}
	return (TRUE);
}

int	ft_empty(char **arg)
{
	int	i;

	i = 0;
	if (!arg[i])
		ft_pushswap_free(1);
	return (TRUE);
}

int	ft_only_number(char **arg, int i)
{
	int	j;

	j = 0;
	while (arg[i])
	{
		while (arg[i][j])
		{
			if (ft_isdigit(arg[i][j]) == 0)
			{
				if (arg[i][j] == '-' && j == 0)
					j++;
				if (ft_isdigit(arg[i][j]) == 0)
					ft_pushswap_free(1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (TRUE);
}
