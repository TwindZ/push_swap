/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:56:59 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/18 16:16:15 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns a pointer to the last occurrence of character <c> in <s>.
The terminating null-character is considered part of the string. Therefore,
it can also be located to retrieve a pointer to the end of a string.*/
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		len--;
	}
	if (s[len] == (char)c)
		return ((char *)s + len);
	return (NULL);
}
