/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:27:26 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/18 16:15:14 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Compares the first <n> bytes of the block of memory pointed by <s1> to 
the first <n> bytes pointed by <s2>, returning zero if they all match or 
a value different from zero(-x or x).*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i != n)
	{
		if ((str1[i] < str2[i]) || (str1[i] > str2[i]))
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (0);
}
