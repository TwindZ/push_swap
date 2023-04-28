/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:57:08 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/28 17:38:07 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*This function checks if the list indexes are sorted in ascending order. 
Return 1 for TRUE*/
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

/*This function checks if the list indexes are sorted in descending order. 
Return 1 for TRUE*/
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

/*This function checks that there are no duplicates in the list, frees all 
allocated memory, and quits if duplicates are found.*/
void	ft_no_double(t_data *data)
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
				ft_pushswap_free(1);
			temp2 = temp2->next;
		}
		temp = temp->next;
		if (temp != NULL)
			temp2 = temp->next;
	}
}

/*This function checks that all characters are numeric, frees all allocated
memory, and exits if a non-numeric character is found.*/
void	ft_only_number(char **arg, int i)
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
}
