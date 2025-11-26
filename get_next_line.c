/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:30:59 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/26 14:51:00 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_endline(char *s)
{
    int i = 0;

    if (!s)
        return -1;
    while (s[i])
    {
        if (s[i] == '\n')
            return i;
        i++;
    }
    return -1;
}

char *read_and_stash(int fd, char *stash)
{
    char buffer[BUFFER_SIZE + 1];
    int n;
	char *tmp;

    while (check_endline(stash) == -1)
    {
        n = read(fd, buffer, BUFFER_SIZE);
        if (n <= 0)
            return stash;

        buffer[n] = '\0';

		if (!stash)
            stash = ft_strdup(buffer);
		else
		{
        	tmp = ft_strjoin(stash, buffer);
			free(stash);
            stash = tmp;
		}
    }
    return stash;
}

char *extract_line(char *stash)
{
    int i = check_endline(stash);

    if (i == -1)
        return ft_strdup(stash);
    return ft_substr(stash, 0, i + 1);
}

char *clean_stash(char *stash)
{
    int i = check_endline(stash);
    char *new_stash;

    if (i == -1)
    {
        free(stash);
        return NULL;
    }
    new_stash = ft_strdup(stash + i + 1);
    free(stash);
	if (!new_stash[0])
    {
        free(new_stash);
        return NULL;
    }
    return new_stash;
}

char *get_next_line(int fd)
{
    static char *stash = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    stash = read_and_stash(fd, stash);
	// printf("stash = [%s]\n", stash);
    if (!stash || !stash[0])
	{
		free(stash);
        stash = NULL;
        return NULL;
	}
    line = extract_line(stash);
    stash = clean_stash(stash);
    return line;
}



