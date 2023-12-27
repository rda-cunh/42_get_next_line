#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char *next_line;
	int	count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	next_line = get_next_line(fd);
	count++;
	// count is to show the line number
	
	printf("[line: %d] buffer: %s\n", count, next_line);
	next_line = NULL; 

	close (fd);
	return (0);
}