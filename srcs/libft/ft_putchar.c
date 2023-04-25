/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:41:29 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/24 21:37:37 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_putchar() - writes a single character to the standard output. */
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
