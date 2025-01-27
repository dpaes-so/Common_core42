/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:46:26 by dpaes-so          #+#    #+#             */
/*   Updated: 2024/11/19 16:46:26 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0)
	{
		if (FOPEN_MAX > fd && fd > 0)
			while (i <= BUFFER_SIZE)
				buffer[fd][i++] = '\0';
		return (NULL);
	}
	str = 0;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer[fd]);
		if (!str)
			return (free(str), NULL);
		buffermove(buffer[fd]);
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
	while (i < 3)
	{
		str = get_next_line(fd);
		printf("RESULT E = %s", str);
		i++;
	}
	i = 0;
	printf("--------------------------------\n");
	while (i < 3)
	{
		str = get_next_line(fd2);
		printf("RESULT E = %s", str);
		i++;
	}
	i = 0;
	printf("--------------------------------\n");
	while (i < 3)
	{
		str = get_next_line(fd);
		printf("RESULT E = %s", str);
		i++;
	}
	printf("NEWLINE TESTE");
	printf("\n");
}*/