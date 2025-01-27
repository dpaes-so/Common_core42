/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:52:31 by dpaes-so          #+#    #+#             */
/*   Updated: 2024/10/30 15:31:54 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
