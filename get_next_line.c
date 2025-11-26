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

int	ft_strlcpy(char *dest, const char *src, size_t size);

char	check_endline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_one_line(char *str, int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char 		*dest;
	int 		size;
	int			n;
	
	while (1)
	{
		size = check_endline(str);
		if (size != -1)
		{
			dest = ft_substr(str, 0, size);
			return (dest);
		}
		n = read(fd, str, BUFFER_SIZE);
		if (n <= 0)
		{
			if (str[0])
				return (ft_strdup(str));
			return(NULL);
		}
		buffer[n] = '\0';
		str = ft_strjoin(str, buffer);
	}
}


char	*get_next_line(int fd)
{
	static char		str[BUFFER_SIZE + 1];
	char 			*dest;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	dest = get_one_line(str, fd);
	return (dest);
}
