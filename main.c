/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:44:42 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/27 15:07:14 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int 	fd = open("file.txt", O_RDONLY);
	int 	n;
	char	*line;

	n = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s%d%s%s\n", "line n", n, " ", line);
		n++;
		free(line);
	}
	close (fd);
	return (0);
}


/*
int	main(void)
{
	int 	fd = open("file.txt", O_RDONLY);
	char	*line;

	
	printf("%s\n", line = get_next_line(fd));
	free(line);
	printf("%s\n", line = get_next_line(fd));
	free(line);
	printf("%s\n", line = get_next_line(fd));
	free(line);
	printf("%s\n", line = get_next_line(fd));
	free(line);
	printf("%s\n", line = get_next_line(fd));
	free(line);
	
	close (fd);
	return (0);
}
*/
