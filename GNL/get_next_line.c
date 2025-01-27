/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:41:53 by dpaes-so          #+#    #+#             */
/*   Updated: 2024/11/19 16:41:53 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0)
	{
		while (i <= BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
		return (NULL);
	}
	str = 0;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(str), NULL);
		buffermove(buffer);
		if (str[ft_linelen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}

/*int	main(void)
{
	int i = 0;
	char *str;
	int fd = open("cat.txt", O_RDONLY);
	int fd2 = open("cat2.txt", O_RDONLY);
	while (i < 4)
	{
		str = get_next_line(fd);
		printf("RESULT E = %s", str);
		i++;
	}
	printf("NEWLINE TESTE");
	printf("\n");
}*/