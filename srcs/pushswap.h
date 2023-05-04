/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:13 by emlamoth          #+#    #+#             */
/*   Updated: 2023/05/03 20:53:03 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define TRUE 1
# define FALSE 0

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
	t_stack	*temp;
	int		stacksize;
	char	**arg;
	int		free_flag;
	int		write_flag;
	int		cost;
	int		base;
	int		argc;
	char	**argv;
	int		div;
}				t_data;

int		ft_find_smallest(t_data *data, char set);
int		ft_find_biggest(t_data *data, char set);
int		ft_inverted_sorted(t_stack *stack);
int		ft_sorted(t_stack *stack);
int		ft_stacksize(t_stack *stack);

t_data	*ft_init(int argc, char **argv);

t_stack	*ft_lstnew_int(int content);
t_stack	*ft_rotstack(t_stack *stack);
t_stack	*ft_rrotstack(t_stack *stack);
t_stack	*ft_stackswap(t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);

void	ft_arg(t_data *data);
void	ft_empty(char **arg, int i);
void	ft_free_stack(t_stack *stack);
void	ft_index(t_data *data);
void	ft_no_double(t_data *data);
void	ft_only_number(char **arg, int i);
void	ft_pushswap_free(int i);
void	ft_push_b(t_data *data);
void	ft_push_a(t_data *data);
void	ft_radix(t_data *data, int base);
void	ft_rot(t_data *data, char set);
void	ft_rrot(t_data *data, char set);
void	ft_stack(t_data *data, int i);
void	ft_simulation(t_data *data);
void	ft_simple_sort(t_data *data);
void	ft_sort_2(t_data *data);
void	ft_sort_3(t_data *data);
void	ft_sort_4(t_data *data);
void	ft_sort_5(t_data *data);
void	ft_swap(t_data *data, char set);
void	ft_write_or_count(t_data *data, char *movename);
void	ft_simulation_free(t_data *fake, int i);

#endif