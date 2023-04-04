/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:19:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/23 10:10:54 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2048
#endif

static char	*ft_stack(int fd, char *stack)
{
	char	*buf;
	int		ret;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret != 0 && ft_strchr(stack, '\n') == NULL)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			free(stack);
			return (NULL);
		}
		buf[ret] = '\0';
		stack = ft_strjoin(stack, buf, 1);
	}
	free(buf);
	return (stack);
}

static char	*ft_over(char *stack)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	line = (char *)malloc((sizeof(char) * ft_strlen(stack) - i) + 1);
	if (!line)
		return (NULL);
	i++;
	while (stack[i])
		line[j++] = stack[i++];
	line[j] = '\0';
	free(stack);
	return (line);
}

static char	*ft_line(char *stack)
{
	char	*line;
	int		i;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] && stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = ft_stack(fd, stack);
	if (!stack)
		return (NULL);
	line = ft_line(stack);
	stack = ft_over(stack);
	return (line);
}
