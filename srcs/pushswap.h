/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:13 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/13 09:49:00 by emlamoth         ###   ########.fr       */
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
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stack	*next;
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

int	ft_empty(char **arg);
int	ft_only_number(char **arg, int i);
int	ft_no_double(t_data *data);
int	ft_stacksize(t_stack *stack);
int	ft_sorted(t_stack *stack);

t_data	*ft_init(int argc, char **argv);

t_stack	*ft_lstnew_int(int content);
t_stack	*ft_rotstack(t_stack *stack);
t_stack *ft_rrotstack(t_stack *stack);
t_stack	*ft_stackswap(t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);

void	ft_printlist(t_stack *list);
void	ft_arg(int argc, char **argv, t_data *data);
void	ft_free_stack(t_stack *stack);
void	ft_index(t_data *data);
void	ft_pushswap_free(int i);
void	ft_push_a(t_data *data);
void	ft_push_b(t_data *data);
void	ft_rot_kind(t_data *data, char set);
void	ft_rrot_kind(t_data *data, char set);
void	ft_stack(t_data *data, int i);
void	ft_swap_kind(t_data *data, char set);

#endif