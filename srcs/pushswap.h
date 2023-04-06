/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:13 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/06 18:12:37 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define TRUE 1
# define FALSE 0

typedef struct s_stack t_stack;

typedef struct s_stack
{
	int		content;
	t_stack	*next;
}				t_stack;
	
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

#endif