/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:29:41 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/03/18 15:39:05 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

static char	*get_nl(int fd, char *buffer, char *str, char *save)
{
	int		i;

	i = 1;
	while (!ft_strchr(str, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		if (!str)
		{
			str = (char *)malloc(1);
			str[0] = '\0';
		}
		buffer[i] = '\0';
		save = str;
		str = ft_strjoin(save, buffer);
		free(save);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*buffer;
	char		*save;

	if (read(fd, 0, 0) == -1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	save = NULL;
	str[fd] = get_nl(fd, buffer, str[fd], save);
	free(buffer);
	save = ft_strnldup(str[fd]);
	str[fd] = ft_exstrchr(str[fd]);
	return (save);
}
