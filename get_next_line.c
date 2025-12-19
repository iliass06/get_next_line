/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:23:42 by iel-fadi          #+#    #+#             */
/*   Updated: 2025/12/16 13:26:24 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// static char	*fill_buffer(int fd, char *left, char *buffer)
// {
// 	ssize_t	i;
// 	char	*tmp;

// 	i = 1;
// 	while ((!left || !ft_strchr(left, '\n')) && i != 0)
// 	{
// 		i = read(fd, buffer, BUFFER_SIZE);
// 		if (i == -1)
// 		{
// 			free(left);
// 			return (NULL);
// 		}
// 		buffer[i] = '\0';
// 		if (!left)
// 			left = ft_strdup(buffer);
// 		else
// 		{
// 			tmp = ft_strjoin(left, buffer);
// 			free(left);
// 			left = tmp;
// 		}
// 	}
// 	return (left);
// }

// static char	*set_line(char *line_buffer)
// {
// 	char	*new_line;
// 	int		i;

// 	i = 0;
// 	if (!line_buffer)
// 		return (NULL);
// 	while (line_buffer[i])
// 	{
// 		if (line_buffer[i] == '\n')
// 		{
// 			new_line = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - (i
// 						+ 1));
// 			line_buffer[i + 1] = '\0';
// 			return (new_line);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*backup;
// 	char		*buffer;
// 	char		*line;
    
//     if (fd < 0 || BUFFER_SIZE < 0)
// 		return (NULL);
// 	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	line = fill_buffer(fd, backup, buffer);
// 	free(buffer);
// 	buffer = NULL;
//     if (!line)
//     {
//         backup = NULL;
//         return(NULL);
//     }
// 	backup = set_line(line);
// 	return (line);
// }

#include "get_next_line.h"

static char *fill_buffer(int fd, char *left, char *buffer)
{
    ssize_t i;
    char    *tmp;

    i = 1;
    while ((!left || !ft_strchr(left, '\n')) && i > 0)
    {
        i = read(fd, buffer, BUFFER_SIZE);
        if (i == -1) // Erreur
        {
            free(left);
            return (NULL);
        }
        if (i == 0) // <--- AJOUT INDISPENSABLE : Fin du fichier
            break;  // On sort immediatement pour ne pas creer de chaine vide

        buffer[i] = '\0';
        if (!left)
            left = ft_strdup(buffer);
        else
        {
            tmp = ft_strjoin(left, buffer);
            free(left);
            left = tmp;
        }
    }
    return (left);
}

static char *set_line(char *line_buffer)
{
    char    *new_line;
    int     i;

    i = 0;
    if (!line_buffer)
        return (NULL);
    while (line_buffer[i])
    {
        if (line_buffer[i] == '\n')
        {
            new_line = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i - 1);
            line_buffer[i + 1] = '\0';
            return (new_line);
        }
        i++;
    }
    return (NULL);
}

char    *get_next_line(int fd)
{
    static char *backup;
    char        *buffer;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
        
    line = fill_buffer(fd, backup, buffer);
    free(buffer);
    
    if (!line) // Si fill_buffer renvoie NULL, on s'assure que backup est NULL
    {
        backup = NULL;
        return (NULL);
    }
    
    backup = set_line(line);
    return (line);
}