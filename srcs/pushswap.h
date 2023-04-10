/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:13 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/10 15:15:04 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define TRUE 1
# define FALSE 0
# define ERRARG "Only number separated by spaces can be in argument.\n"
# define ERRDUP "No duplication allow.\n"
# define ERRINT "Off range of int detected\n"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <limits.h>

typedef struct s_stack t_stack;
typedef struct s_data t_data;

typedef struct s_stack
{
	int		content;
	t_stack	*next;
}				t_stack;

typedef struct s_data
{
	t_stack	*stack;
	t_stack *temp;
	char	**arg;
	int		len;
	int		free_flag;
}				t_data;

#endif