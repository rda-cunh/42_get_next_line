/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:54 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/01/12 14:00:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*append_buffer(char *basin_buffer, char *read_buffer)



//Function to read data from the file and create partial content. 

static char	*read_from_file(static char *basein_buffer, int fd)
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
		basein_buffer = append_buffer(basein_buffer, cup_buffer);
		if (ft_strchr(basein_buffer, '\n'))
			break ;
	}
	free (cup_buffer);
	return (basein_buffer);
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
