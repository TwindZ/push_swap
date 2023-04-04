/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:41:39 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/15 13:21:35 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countnb(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_un(unsigned int n)
{
	unsigned int	count;

	count = countnb(n);
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr_un(n / 10);
		ft_putnbr_un(n % 10);
	}
	return (count);
}
