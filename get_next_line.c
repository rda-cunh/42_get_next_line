/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:54 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/01/02 17:23:33 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//Function to read data from the file and create partial content. 

static char	*read_from_file(int fd)
{
	int		bytes_read;
	char	*buffer;
	static int	count = 1;
	
	printf("ft_calloc#[%d]---", count++);
	buffer = ft_calloc(3+1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, 3);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

// function to get the next line from the file descriptor.

char	*get_next_line(int fd)
{
	char	*base_buffer;
	
	base_buffer = read_from_file(fd);
	return (base_buffer);
}