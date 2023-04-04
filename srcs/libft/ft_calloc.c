/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:04 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/18 16:14:23 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The ft_calloc() function shall allocate unused space for an array of
<count> elements each of whose size in bytes is <size>.  The space
shall be initialized to all bits 0.*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = (malloc(count * size));
	if (!a)
		return (NULL);
	ft_bzero(a, count * size);
	return (a);
}
