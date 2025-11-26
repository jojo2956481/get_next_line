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
			dest = ft_substr(str, 0, size + 1);
			ft_strlcpy(str, str + size + 1, BUFFER_SIZE + 1);
			return (dest);
		}
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
		{
			if (str[0])
			{
				return (ft_strdup(str));
				str[0] = '\0';
			}
			return(NULL);
		}
		buffer[n] = '\0';
		ft_strlcat(str, buffer, BUFFER_SIZE + 1);
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
