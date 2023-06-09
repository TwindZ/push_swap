/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:57:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/24 21:31:47 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The function ft_itoa() converts an integer to a dynamically allocated 
string using malloc.*/
static size_t	ft_size(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/*Converts an integer value to a null-terminated string.*/
char	*ft_itoa(int n)
{
	char			*str;
	size_t			size;
	long int		nb;

	size = ft_size(n);
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		size++;
	}
	str = (char *)malloc(size + 1 * (sizeof(char)));
	if (!str)
		return (NULL);
	str[size] = 0;
	while (size--)
	{
		str[size] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
