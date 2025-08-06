/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_lib_or_not_to_lib.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:47:16 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/08/06 17:13:28 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sinal;

	i = 0;
	result = 0;
	sinal = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal = -sinal;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sinal);
}

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*array;

	i = 0;
	array = (unsigned char *)str;
	while (i < n)
	{
		array[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*buffer;

	if (num && size > (size_t)(-1) / num)
		return (NULL);
	buffer = malloc(num * size);
	if (buffer == NULL)
		return (NULL);
	if (num == 0 || size == 0)
		return (buffer);
	ft_bzero(buffer, num * size);
	return (buffer);
}
