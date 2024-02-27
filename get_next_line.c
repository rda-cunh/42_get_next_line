/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:54 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/02/27 00:13:52 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

char	*get_current_buffer(int fd, char *buffer,)
{
	size_t		bytes_read;
	char		*current_buffer;

	bytes_read = 1;
	current_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!current_buffer)
		return (NULL);
	bytes_read = 1; 
	while (bytes_read > 0 && !find_chr(buffer, '\n'))
	{
		bytes_read = read(fd, current_buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			free(current_buffer);
			return (NULL);
		}
		current_buffer[bytes_read] = '\0';
		buffer = merge_previous_and_current(buffer, current_buffer);
	}
	free (current_buffer);
	if (strlen_at(buffer, '\0') > 0)
		return (buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || read(fd, NULL, 0) > 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_current_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(&buffer);
	if (!buffer[0])
	{
		free (buffer);
		buffer = NULL;
	}
	return (line);
}
