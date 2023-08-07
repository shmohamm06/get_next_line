* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:54:27 by shmohamm          #+#    #+#             */
/*   Updated: 2023/08/07 12:37:51 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *str, int fd)
{
	int		line_number;
	char	*buffer;

	buffer = malloc((long)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line_number = 1;
	while (!ft_strchr(str, '\n') && line_number != 0)
	{
		line_number = read(fd, buffer, BUFFER_SIZE);
		if (line_number < 0)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[line_number] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (0);
	str = read_line(str, fd);
	if (!str)
		return (NULL);
	line = line_by_line(str);
	str = del_line(str);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("how.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
