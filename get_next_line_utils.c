/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:44:49 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/01 10:23:57 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_secure_alloc(char *static_buff, char *buffer)
{
	free(static_buff);
	free(buffer);
	static_buff = NULL;
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		len;
	int		len1;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = 0;
	while (s1[len] != '\0')
		len++;
	len1 = 0;
	while (s2[len1] != '\0')
		len1++;
	size = len + len1;
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (0);
	ft_strlcpy(str, (char *)s1, len + 1);
	ft_strlcpy(&str[len], (char *)s2, len1 + 1);
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

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;
	int		size;

	i = 0;
	size = 0;
	while (s[size] != '\0')
		size++;
	dest = malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (0);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	size;

	if (s == NULL)
		return (0);
	i = 0;
	size = 0;
	while (s[size] != '\0')
		size++;
	if ((size_t)start >= size)
		return (malloc(sizeof(char) * 1));
	if (len > (size - start))
		len = size - start;
	substr = malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	while (i < len)
	{
		substr[i] = (char)s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
