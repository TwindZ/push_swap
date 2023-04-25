/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:01:07 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/24 21:55:26 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_strjoin() - A function that concatenates two strings into a new 
dynamically allocated string. Returns a pointer to the resulting string.
The fr parameter is used to specify whether to free the s1 string. If fr 
is true, the function will free s1. */
char	*ft_strjoin(char *s1, char *s2, int fr)
{
	unsigned int	lens1;
	unsigned int	lens2;
	char			*newstr;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = (char *)malloc(lens1 + lens2 + 1 * (sizeof(char)));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s1, lens1);
	ft_memcpy(newstr + lens1, s2, lens2);
	newstr[lens1 + lens2] = '\0';
	if (fr == 1)
		free(s1);
	return (newstr);
}
