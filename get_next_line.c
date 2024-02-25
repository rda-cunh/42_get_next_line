/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:54 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/02/25 00:34:50 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* -------------------------------------------------------------------------- */
/* Function to append the read buffer data to the partial content (line).     */
/* The explorer (get_next_line) gracefully adds a scoop of water (read        */
/* buffer) to the current cup (line) and returns the updated line for         */
/* further examination.                                                       */
/* -------------------------------------------------------------------------- */

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

/* -------------------------------------------------------------------------- */
/* Function to read data from the file and append it to partial content.      */
/* The explorer dips its magical thimble (buffer) into the aquarium (file)    */
/* and retrieves a scoop of water (characters from the file). The explorer    */
/* continues scooping until it encounters the special fish (newline) or       */
/* examines the entire thimble (buffer).                                      */
/* -------------------------------------------------------------------------- */

char	*read_from_file(char *basin_buffer, int fd)
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

/*------------------------------------------------------------------------ */
/* The main function to get the next line (fish) from the file descriptor. */
/* Alex (get_next_line) gracefully reads lines from the                    */
/* magical aquarium (input file) using the cup (buffer). Alex aims to find */
/* and return each fish (line) one at a time without disturbing            */
/* the rest of the aquarium (file) and avoiding reading the entire file    */
/* at once. The explorer also handles edge cases and errors elegantly.     */
/* ----------------------------------------------------------------------- */

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
