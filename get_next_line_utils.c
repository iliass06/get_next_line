/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fadi <iel-fadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:23:37 by iel-fadi          #+#    #+#             */
/*   Updated: 2025/12/08 01:26:29 by iel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char *ft_strchr(const char *s, int c)
{
    while (s)
    {
        if (*s == (char)c)
            return (s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}

size_t ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
}

char *ft_strdup(const char *s)
{
    char *dup;
    int len;
    int i;

    if (!s)
        return (NULL);
    i = 0;
    len = ft_strlen(s);
    dup = malloc((len + 1) * sizeof(char));
    if (!dup)
        return (NULL);
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof(char const));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	out = malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (s1[i])
		out[j++] = s1[i++];
	i = 0;
	while (s2[i])
		out[j++] = s2[i++];
	out[j] = '\0';
	return (out);
}