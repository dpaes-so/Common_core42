/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:56:01 by dpaes-so          #+#    #+#             */
/*   Updated: 2024/11/04 14:38:51 by dpaes-so         ###   ########.fr       */
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

void	check_null(unsigned long int nb, char *base, int *counter)
{
	if (!nb)
	{
		write(1, "(nil)", 5);
		(*counter) += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*counter) += 2;
		ft_putptr(nb, base, counter);
	}
}

void	ft_putptr(unsigned long int nb, char *base, int *counter)
{
	unsigned long int	len;

	len = ft_strlen(base);
	if (nb < len)
		ft_putcharf(base[nb], counter);
	else
	{
		ft_putptr(nb / len, base, counter);
		ft_putptr(nb % len, base, counter);
	}
}
