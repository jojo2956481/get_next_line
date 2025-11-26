/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:44:49 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/26 14:31:44 by lebeyssa         ###   ########lyon.fr   */
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i != n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	int		size;

	i = 0;
	size = ft_strlen((char *)s);
	dest = malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (0);
	while ((char)s[i] != '\0')
	{
		dest[i] = (char)s[i];
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
	size = ft_strlen((char *)s);
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

