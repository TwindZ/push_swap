/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:56:46 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/18 16:16:12 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Ft_strnstr searches at most <len> characters to locate the first 
occurrence in the string pointed to by <str> of the sequence of characters 
(excluding the terminating null character)in the string pointed to by <ndl>.
Ft_strnstr returns a pointer to the located string, or a null pointer if the 
string is not found. If <ndl> points to a string with zero length, 
ft_strnstr returns <str>*/
char	*ft_strnstr(const char *str, const char *ndl, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!str || !ndl)
		return (NULL);
	if (ndl[j] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		if (str[i] == ndl[0])
		{
			j = 0;
			while (ndl[j] && str[i + j] == ndl[j] && i + j < len)
				j++;
			if (ndl[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
