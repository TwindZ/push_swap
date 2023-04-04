/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:41:32 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/15 13:21:43 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnb(int n)
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

int	ft_putnbr(int n)
{
	int		s;
	int		nb;

	s = 0;
	nb = n;
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb *= -1);
	}	
	else if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (n < 0)
		s = 1;
	return (ft_countnb(n) + s);
}
