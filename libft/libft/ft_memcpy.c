/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:49:30 by dpaes-so          #+#    #+#             */
/*   Updated: 2024/10/28 12:45:17 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*arrayd;
	unsigned char	*arrays;

	i = 0;
	arrayd = (unsigned char *)dest;
	arrays = (unsigned char *)src;
	while (i < n)
	{
		arrayd[i] = arrays[i];
		i++;
	}
	return (dest);
}
