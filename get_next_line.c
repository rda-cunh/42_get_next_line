/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:54 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/01/26 19:12:42 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//Function to append the read buffer data to the partial content (line)

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

//Function to read data from the file and create partial content

static char	*read_from_file(static char *basin_buffer, int fd)
{
	int			bytes_read;
	char		*cup_buffer;

	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (cup_buffer == NULL)
		return (NULL);
	bytes_read = 1; 
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			return (NULL);
		}
		cup_buffer[bytes_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break ;
	}
	free (cup_buffer);
	return (basin_buffer);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char	*line;

	if (fd < 0 || read(fd, NULL, 0) > 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basin_buffer)
		basin_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
		return (free(basin_buffer), NULL);
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	return (line);
}
