/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fercarva <fercarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 00:51:45 by fercarva          #+#    #+#             */
/*   Updated: 2026/11/15 02:08:38 by fercarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*remain;

	if (!stash)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != SEPARATOR)
		i++;
	if (stash[i] == SEPARATOR)
		i++;
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i + j])
		j++;
	remain = malloc(j + 1);
	if (!remain)
		return (NULL);
	j = 0;
	while (stash[i])
		remain[j++] = stash[i++];
	remain[j] = '\0';
	return (remain);
}

char	*ft_extract_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	if (!stash)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != SEPARATOR)
		i++;
	if (stash[i] == SEPARATOR)
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_read_stash(char *stash, char *buffer, int fd)
{
	ssize_t		bytes_read;
	char		*temp;

	temp = NULL;
	while (!stash || !ft_strchr(stash, SEPARATOR))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
		{
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		if (!temp)
		{
			free(stash);
			return (NULL);
		}
		free(stash);
		stash = temp;
	}
	return (stash);
}

char	*get_line_final(char *stash[])
{
	char	*line;
	char	*remain;

	line = ft_extract_line(*stash);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	remain = ft_update_stash(*stash);
	free(*stash);
	*stash = remain;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buffer;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_read_stash(stash[fd], buffer, fd);
	free(buffer);
	return (get_line_final(&stash[fd]));
}
