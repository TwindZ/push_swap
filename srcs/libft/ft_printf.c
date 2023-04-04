/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:41:19 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/23 09:42:45 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convert(const char *str, int i, va_list arg)
{
	if (str[i] == '%')
		return (ft_putchar('%'));
	else if (str[i] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (str[i] == 'u')
		return (ft_putnbr_un(va_arg(arg, unsigned int)));
	else if (str[i] == 'x' || str[i] == 'X')
		return (ft_putnbr_hex(va_arg(arg, unsigned int), str[i]));
	else if (str[i] == 'p')
	{
		ft_putstr("0x");
		return ((ft_putnbr_hex(va_arg(arg, uintptr_t), str[i])) + 2);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_convert(str, ++i, arg);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
