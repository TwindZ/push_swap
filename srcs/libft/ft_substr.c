/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:07:02 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/27 17:28:20 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns a newly constructed string object with its value initialized to a 
copy of a substring of this object. The substring is the portion of the object 
that starts at character position <start> and spans <len> characters (or until 
the end of the string, whichever comes first).*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	new = malloc((len + 1) * (sizeof(char)));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}
