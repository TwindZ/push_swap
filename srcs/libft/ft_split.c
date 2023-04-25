/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:36:24 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/24 21:50:33 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	ft_wcount(char const *s, char c)
{
	int		i;
	int		j;
	char	last;

	i = 0;
	j = 0;
	last = c;
	while (s[i])
	{
		if (last == c && s[i] != c)
			j++;
		last = s[i];
		i++;
	}
	return (j);
}

static char	**ft_tab(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = i;
			while (s[i] && s[i] != c)
				i++;
			tab[j] = ft_substr(s, k, i - k);
			if (!tab[j])
				return (ft_freeall(tab));
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

/*This function splits a string into an array of substrings
based on a delimiter. Returns a pointer to the resulting array. The function 
uses dynamic memory allocation and can handle multiple delimiters. The last 
element of the array is set to NULL. */
char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc((ft_wcount(s, c) + 1) * (sizeof(char *)));
	if (!tab)
		return (NULL);
	tab = ft_tab(tab, s, c);
	return (tab);
}
