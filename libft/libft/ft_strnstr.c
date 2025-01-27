/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:46:47 by dpaes-so          #+#    #+#             */
/*   Updated: 2024/10/29 11:20:36 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *hay, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return (hay);
	while (hay[i] != '\0' && i < n)
	{
		j = 0;
		while (needle[j] != '\0' && hay[i + j] == needle[j] && (i + j) < n)
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return (hay + i);
		}
		i++;
	}
	return (NULL);
}
