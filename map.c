/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:03:46 by duccello          #+#    #+#             */
/*   Updated: 2025/07/14 19:03:48 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_check(t_map *map)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	j = 0;
	exit = 0;
	while (map->m[i] != NULL)
	{
		j = 0;
		while (map->m[i][j])
		{
			if (map->m[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (0);
	return (1);
}

int	bounds(t_map *map)
{
	int	i;

	i = 0;
	while (map->m[i] != NULL)
	{
		if (ft_strlen(map->m[i]) != map->w || map->m[i][0] != '1'
			|| map->m[i][map->w - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map->m[0][i] != '\0')
	{
		if (map->m[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map->m[map->h - 1][i] != '\0')
	{
		if (map->m[map->h - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (i == 0)
	{
		while (map->m[j] != NULL && (!ft_strchr(map->m[j], 'P')))
			j++;
		if (map->m[j] == NULL)
			return (0);
		while (map->m[j][i] != 'P')
			i++;
		map->x = i;
		map->y = j;
	}
	while (map->m[j][++i])
		if (map->m[j][i] == 'P')
			return (0);
	while (map->m[++j] != NULL)
		if (ft_strchr(map->m[j], 'P'))
			return (0);
	return (1);
}

int	check_map(t_map *map)
{
	map->t_c = 0;
	map->w = ft_strlen(map->m[0]);
	map->c_m = 0;
	map->c_c = 0;
	if (position(map) == 0)
		return (0);
	if (bounds(map) == 0)
		return (0);
	if (collectibles(map) == 0)
		return (0);
	if (exit_check(map) == 0)
		return (0);
	if (path(map) == 0)
		return (0);
	else
		return (1);
}

int	count_lines(char *file)
{
	int		l;
	int		fd;
	char	*line;

	l = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		l++;
		line = get_next_line(fd);
	}
	close(fd);
	return (l);
}
