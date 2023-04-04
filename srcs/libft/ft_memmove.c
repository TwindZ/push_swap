/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:22:12 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/18 16:15:20 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copies the values of <n> bytes from the location pointed by <src> to the 
memory block pointed by <dst>. Copying takes place as if an intermediate
buffer were used, allowing the destination and source to overlap.*/
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*dest;
	char			*source;

	dest = (char *)dst;
	source = (char *)src;
	if (!dst || !src)
		return (dst);
	if (source < dest)
	{
		while (n--)
			dest[n] = source[n];
	}
	else
		ft_memcpy(dest, source, n);
	return (dest);
}
