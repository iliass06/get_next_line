
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;

	// 1. On prepare le fichier
	fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	write(fd, "1\n234", 5);
	close(fd);

	// 2. On le rouvre pour lire depuis le DEBUT
	fd = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}