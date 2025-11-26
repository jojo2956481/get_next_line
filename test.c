/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:26:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/26 12:21:35 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	check_endline(char *str, int size)
{
	int	i;

	i = 0;
	while (i != size)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		str[BUFFER_SIZE];
	char		*dest;
	int 		i;
	int			n;

	if (BUFFER_SIZE == 0)
		return (0);
	dest = malloc(sizeof(char) * 40);
	if (dest == NULL)
		return (0);
	n = read(fd, &str, BUFFER_SIZE);
	if (n < BUFFER_SIZE && check_endline(str, BUFFER_SIZE) == 0)
	{
		ft_strlcpy(dest, str, n + 1);
		return (dest);
	}
	if (check_endline(str, BUFFER_SIZE) == 1)
	{
		i = 0;
		while (str[i] != '\n')
			i++;
		ft_strlcpy(dest, str, i + 1);
		return (dest);
	}
	while (check_endline(str, BUFFER_SIZE) != 1 && n == BUFFER_SIZE)
	{
		dest = ft_strjoin(dest, str);
		n = read(fd, &str, BUFFER_SIZE);
	}
	i = 0;
	while ((str[i] != '\n') && (i < n))
		i++;
	ft_strlcpy(str, str, i + 1);
	dest = ft_strjoin(dest, str);
	return (dest);
}