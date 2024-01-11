/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:54 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/01/11 18:40:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//Function to read data from the file and create partial content. 

static char	*read_from_file(int fd)
{
	int			bytes_read;
	char		*buffer;
	static int	count = 1;

	printf("ft_calloc#[%d]---", count++);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*basein_buffer;
	char	*line

	if (fd < 0 || read(fd, NULL, 0) > 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basein_buffer)
		basein_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(basein_buffer, '\n'))
		basein_buffer = read_from_file(basein_buffer, fd);
	if (!basein_buffer)
		return (free(basein_buffer), NULL);
	line = extract_line(basein_buffer);
	basein_buffer = obtain_remaining(basein_buffer);
	return (line);
}
