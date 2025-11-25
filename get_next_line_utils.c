/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:44:49 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/25 13:54:31 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen((char *)s1);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (0);
	ft_strlcpy(str, (char *)s1, ft_strlen((char *)s1) + 1);
	ft_strlcpy(&str[len], (char *)s2, ft_strlen((char *)s2) + 1);
	return (str);
}

int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}



