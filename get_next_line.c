/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:30:59 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/27 14:00:21 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_endline(char *s)
{
    int i = 0;

    if (!s)
        return (-1);
    while (s[i])
    {
        if (s[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char	*read_and_stock(int fd, char *static_buff)
{
	char	buffer[BUFFER_SIZE + 1];
	int 	n;
	char	*

	while (check_endline(static_buff) == -1)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		if (n == 0)
		{
			break;
		}
		buffer[n] = '\0';
		if (!static_buff)
			static_buff = ft_strdup(buffer);
		else
			static_buff = ft_strjoin(static_buff, buffer);
	}
	return (static_buff);
}

char	*get_one_line(char *static_buff)
{
	int i;
	
	i = check_endline(static_buff);
	if (i == -1)
		return (ft_strdup(static_buff));
	return (ft_substr(static_buff, 0, i + 1));
}

char *clean_and_stock(char *static_buff)
{
	char	*new_buff;
	int		i;

	i = check_endline(static_buff);
	if (i == -1)
		new_buff = NULL;
	else
	{
		new_buff = ft_strdup(&static_buff[i + 1]);
		if (!new_buff)
		{
			free(new_buff);
        	return (NULL);
		}
	}
	free(static_buff);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*static_buff;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_endline(static_buff) == -1 && static_buff != NULL)
	{
		line = ft_strdup(static_buff);
	}
	else
		static_buff = read_and_stock(fd, static_buff);
	if (!static_buff)
        return (NULL);
	if (!line)
		line = get_one_line(static_buff);
	static_buff = clean_and_stock(static_buff);
	return (line);
}


