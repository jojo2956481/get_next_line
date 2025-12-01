/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:31:31 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/01 10:22:00 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//#ifndef BUFFER_SIZE
//# define BUFFER_SIZE 1
//#endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_secure_alloc(char *static_buff, char *buffer);

#endif