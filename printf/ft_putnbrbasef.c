/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbasef.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:55:00 by dpaes-so          #+#    #+#             */
/*   Updated: 2024/11/04 14:28:47 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putnbrbasef(unsigned int nb, char *base, int *counter)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (nb < len)
		ft_putcharf(base[nb], counter);
	else
	{
		ft_putnbrbasef(nb / len, base, counter);
		ft_putnbrbasef(nb % len, base, counter);
	}
}
