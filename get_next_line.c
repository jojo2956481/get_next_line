/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:30:59 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/01 12:57:53 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_endline(char *s)
{
	int	i;

	i = 0;
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

char	*read_and_stock(int fd, char *static_buff, char *buffer)
{
	int		n;
	char	*tmp;

	while (check_endline(static_buff) == -1)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (ft_secure_alloc(static_buff, buffer));
		if (n == 0)
			break ;
		buffer[n] = '\0';
		if (!static_buff)
			static_buff = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(static_buff, buffer);
			if (!tmp)
				return (ft_secure_alloc(static_buff, buffer));
			free(static_buff);
			static_buff = tmp;
		}
	}
	free(buffer);
	return (static_buff);
}

char	*get_one_line(char *static_buff)
{
	int	i;

	if (!static_buff)
		return (NULL);
	i = check_endline(static_buff);
	if (i == -1)
		return (ft_strdup(static_buff));
	return (ft_substr(static_buff, 0, i + 1));
}

char	*clean_and_stock(char *static_buff)
{
	char	*new_buff;
	int		i;

	i = check_endline(static_buff);
	if (i == -1)
	{
		free(static_buff);
		return (NULL);
	}
	else
	{
		new_buff = ft_strdup(&static_buff[i + 1]);
		free(static_buff);
		if ((!new_buff) || (new_buff[0] == '\0'))
		{
			free(new_buff);
			return (NULL);
		}
	}
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*static_buff;
	char		*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	static_buff = read_and_stock(fd, static_buff, buffer);
	if (!static_buff)
		return (NULL);
	line = get_one_line(static_buff);
	if (!line)
	{
		free(static_buff);
		static_buff = NULL;
		return (NULL);
	}
	static_buff = clean_and_stock(static_buff);
	return (line);
}
