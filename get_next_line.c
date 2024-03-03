/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:54 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/03/03 12:52:20 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *buffer)
{
	char	*line;
	char	*keep;
	size_t	til_null;
	size_t	til_new;

	til_new = strlen_at(*buffer, '\n')
	if ((*buffer)[til_new] == '\n')
		til_new++;
	line = cpy_buffer(*buffer, til_new);
	if (!line)
		return (NULL);
	til_null = strlen_at(*buffer, '\0')
	keep = cpy_buffer(*buffer + til_new, til_null - til_new + 1);
	if (!keep)
	{
		free (line);
		return (NULL);
	}
	free(*buffer)
	*buffer = keep;
	return (line);	
}

static char	*get_current_buffer(int fd, char *buffer,)
{
	size_t		bytes_read;
	char		*current_buffer;

	bytes_read = 1;
	current_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!current_buffer)
		return (NULL);
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
	char		*line;

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
/*
int	main(int argc, char const *argv[])
{
	int		fd;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
/*

