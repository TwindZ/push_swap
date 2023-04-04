/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:10:07 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/18 16:15:22 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The ft_memset() function copies the character <c> (an unsigned char) 
to the first <len> characters of the string pointed to, by the argument <s>.*/
void	*ft_memset(void *s, int c, size_t len)
{
	unsigned int		i;
	unsigned char		*str;

	str = (unsigned char *)s;
	i = 0;
	if (!s)
		return (NULL);
	while (i < len)
		str[i++] = c;
	return (str);
}
