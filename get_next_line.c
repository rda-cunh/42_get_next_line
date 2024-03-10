/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:54 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/03/10 17:09:32 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//	function that reads file, stores string in the buffer and joins it to data

static	int	read_buffer(int fd, char **data, char *buffer)
{
	char	*tmp;
	int		bytes;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0 || buffer == NULL)
	{
		free(*data);
		*data = NULL;
		return (-1);
	}
	if (bytes == 0)
		return (bytes);
	tmp = ft_strjoin(*data, buffer);
	free(*data);
	*data = tmp;
	return (bytes);
}

//	Takes the string/line to return from data

static void	get_line(char **data, char **line)
{
	char	*nl;
	size_t	len;
	size_t	i;

	nl = ft_strchr(*data, '\n');
	len = ft_strlen(*data) - ft_strlen(nl) + 2;
	*line = (char *)malloc(len * sizeof(char));
	if (!line)
		return ;
	i = 0;
	while (i < len - 1)
	{
		(*line)[i] = (*data)[i];
		i++;
	}
	(*line)[i] = '\0';
}

//	Removes the string/line obtained in get_line() from data

static void	remove_line(char **data)
{
	char	*nl;
	char	*tmp;
	size_t	i;
	size_t	j;

	nl = ft_strchr(*data, '\n');
	if (!nl)
	{
		free(*data);
		*data = NULL;
		return ;
	}
	tmp = malloc((ft_strlen(nl) + 1) * sizeof(char));
	i = 0;
	j = ft_strlen(*data) - ft_strlen(nl) +1;
	while (j < ft_strlen(*data))
		tmp[i++] = (*data)[j++];
	tmp[i] = '\0';
	free(*data);
	*data = tmp;
	if (**data == 0)
	{
		free(*data);
		*data = NULL;
	}
}

//	get next line main function

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;
	char		*buffer;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes = 1;
	while (ft_strchr(data, '\n') == NULL && bytes > 0)
		bytes = read_buffer(fd, &data, buffer);
	free(buffer);
	if (bytes == -1)
		return (NULL);
	if (ft_strlen(data) == 0)
		return (NULL);
	get_line(&data, &line);
	remove_line(&data);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	int		linenumber;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	linenumber = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		linenumber++;
		printf("[%d]: %s", linenumber, line);
	}
	printf("\n");
	close(fd);
	return (0);
}
*/