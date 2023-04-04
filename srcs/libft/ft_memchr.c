/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:37:25 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/18 16:15:11 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The ft_memchr() function searches for the first occurrence 
of the character <c> (an unsigned char) in the first <n> bytes of 
the string pointed to, by the argument <s>.*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int			i;
	const unsigned char		*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
