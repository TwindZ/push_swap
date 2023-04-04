/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/04 15:12:17 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	int i;

	i = 1;	
	if(argc == 2)
	{
		// ft_split();
	}
	else if (argc > 2)
	{
		while(argv[i])
		{	
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			i++;
			
		}
	}
	else
		ft_putstr("\n\e[31mNothing to sort !\e[0m\n\n");
}