/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:54 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/03/12 23:37:41 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

//	Takes the line/string to return from data

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

//	Removes the line/string obtained in get_line() from data

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
	j = ft_strlen(*data) - ft_strlen(nl) + 1;
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

//	get next line main function that reads from multiple files
// and uses an array of pointers to store the information 

char	*get_next_line(int fd)
{
	static char	*data[MAX_FILES];
	char		*line;
	char		*buffer;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FILES)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes = 1;
	while (ft_strchr((data[fd]), '\n') == NULL && bytes > 0)
		bytes = read_buffer(fd, &(data[fd]), buffer);
	free(buffer);
	if (bytes == -1)
		return (NULL);
	if (ft_strlen(data[fd]) == 0)
		return (NULL);
	get_line(&(data[fd]), &line);
	remove_line(&(data[fd]));
	return (line);
}
/*
int	main(void)
{
	int		fd[2];
	char	*line;

	fd[0] = open("example.txt", O_RDONLY);
	if (fd[0] < 0)
	{
		perror("Error opening file");
		return (1);
	}

	fd[1] = open("example2.txt", O_RDONLY);
	if (fd[1] < 0)
	{
		perror("Error opening file");
		close(fd[0]);
		return (1);
	}

	while ((line = get_next_line(fd[0])) != NULL)
	{
		printf("%s\n",  line);
		free(line);
	}
	close(fd[0]);
	
	while ((line = get_next_line(fd[1])) != NULL)
	{
		printf("%s\n",  line);
		free(line);
	}
	close(fd[1]);
	
	return (0);
}
*/