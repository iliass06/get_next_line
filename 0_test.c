#include"get_next_line.h"
#include<fcntl.h>

// 

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    // 1. On prepare le fichier
    fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
    write(fd, "1\n234", 5);
    close(fd);

    // 2. On le rouvre pour lire depuis le DEBUT
    fd = open("test.txt", O_RDONLY);
    
    // 3. Boucle de lecture securisee
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL) // ARRET SI NULL
            break;
        printf("Ligne : %s", line); // Le \n est deja dans la ligne
        free(line);
    }
    
    close(fd);
    return (0);
}