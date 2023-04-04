/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:41:35 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/15 13:21:28 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countnb(uintptr_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_putnbr_hex(uintptr_t n, char c)
{
	unsigned int	count;
	char			*base;
	char			*base2;

	count = 0;
	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (c == 'X')
		base = base2;
	if (n < 16)
		write (1, &base[n], 1);
	else
	{
		ft_putnbr_hex(n / 16, c);
		ft_putnbr_hex(n % 16, c);
	}
	count = countnb(n);
	return (count);
}
