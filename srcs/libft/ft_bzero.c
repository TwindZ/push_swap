/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:30:55 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/18 16:14:20 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The ft_bzero() function erases the data in the <n> bytes of the memory
starting at the location pointed to by <s>, by writing zeros (bytes
containing '\0') to that area.*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
