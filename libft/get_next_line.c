/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:20:44 by duccello          #+#    #+#             */
/*   Updated: 2025/06/10 10:20:49 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*free_strjoin(char *stash, char *buffer)
{
	char	*new;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(stash) + ft_strlen(buffer) + 1;
	new = (char *)malloc(len + 1 * sizeof(char));
	if (!new)
		return (NULL);
	while (stash[i] && i < (ft_strlen(stash) + 1))
	{
		new[i] = stash[i];
		i++;
	}
	new[i] = '\0';
	ft_strlcat(new, buffer, len);
	free(stash);
	return (new);
}

char	*read_and_append(char *stash, int fd, int *bytes_red)
{
	char	buffer[BUFFER_SIZE + 1];

	if (stash == NULL)
	{
		*bytes_red = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_red <= 0)
			return (NULL);
		buffer[*bytes_red] = '\0';
		stash = ft_strdup(buffer);
	}
	while (!ft_strchr(stash, '\n') && *bytes_red > 0)
	{
		*bytes_red = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_red <= 0)
			break ;
		buffer[*bytes_red] = '\0';
		stash = free_strjoin(stash, buffer);
	}
	return (stash);
}

char	*extrct_line(char *stash)
{
	int		i;
	char	*new;

	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		i++;
	}
	i++;
	new = ft_substr(stash, 0, i);
	return (new);
}

char	*trim_stash(char *stash)
{
	int		i;
	char	*temp;

	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		i++;
	}
	i++;
	temp = ft_substr(stash, i, ft_strlen(stash));
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	static int	bytes_red = -1;
	char		*line;

	if (fd < 0 || fd > 1023)
		return (NULL);
	stash = read_and_append(stash, fd, &bytes_red);
	if (bytes_red <= 0 && stash == NULL)
		return (NULL);
	if (bytes_red == -1)
	{
		free(stash);
		stash = NULL;
		return (stash);
	}
	line = extrct_line(stash);
	stash = trim_stash(stash);
	if (!line || *line == '\0')
	{
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
