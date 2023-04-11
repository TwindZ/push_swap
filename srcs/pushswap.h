/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:13 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/11 16:59:47 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define TRUE 1
# define FALSE 0
# define ERRARG "Only number separated by spaces can be in argument.\n"
# define ERRDUP "No duplication allow.\n"
# define ERRINT "Off range of int detected\n"

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack t_stack;
typedef struct s_data t_data;

typedef struct s_stack
{
	int		index;
	int		content;
	t_stack	*next;
}				t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *temp;
	int		stacksize;
	char	**arg;
	int		free_flag;
}				t_data;

int	ft_stacksize(t_stack *stack);

t_stack *ft_rrotstack(t_stack *stack);
t_stack	*ft_rotstack(t_stack *stack);
t_stack	*ft_stackswap(t_stack *stack);

void	ft_push_a(t_data *data);
void	ft_push_b(t_data *data);
void	ft_rot_kind(t_data *data, char set);
void	ft_rrot_kind(t_data *data, char set);
void	ft_swap_kind(t_data *data, char set);

#endif