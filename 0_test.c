#include "get_next_line.h"
#include<stdio.h>
#include <fcntl.h>
#include<string.h>

int main()
{
	int fd;
	// char *line;

	fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (1);
	write(fd, "A", 4);
	close(fd);

	fd = open("test.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	return (0);
}
