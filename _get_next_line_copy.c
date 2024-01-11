/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:54 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/01/09 19:25:24 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// function to convert and print the newline character as ?  

void    print_newline_helper(char *buffer)
{

    while (*buffer &&  *buffer != '\0')
    {
        if (*buffer == '\n') 
        {
            *buffer= '\\';
        }
        printf("%c",*buffer);
        buffer++;
    }
}

// function to read data from the file and create partial content. 

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
	print_newline_helper(cup_buffer);
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
