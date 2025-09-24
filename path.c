/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:03:59 by duccello          #+#    #+#             */
/*   Updated: 2025/07/14 19:04:00 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectibles(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->m[i] != NULL)
	{
		j = 0;
		while (map->m[i][j])
		{
			if (map->m[i][j] != 'C' && map->m[i][j] != 'E'
				&& map->m[i][j] != '1' && map->m[i][j] != 'P'
				&& map->m[i][j] != '0')
				return (0);
			if (map->m[i][j] == 'C')
				map->t_c++;
			j++;
		}
		i++;
	}
	if (map->t_c == 0)
		return (0);
	return (1);
}

int	solve(char **map, int y, int x, int *turnips)
{
	static int	exit = 0;

	if (map[y][x] == '1' || map[y][x] == '2')
		return (exit);
	if (map[y][x] == 'C')
		*turnips += 1;
	if (map[y][x] == 'E')
		exit = 1;
	map[y][x] = '2';
	solve(map, y + 1, x, turnips);
	solve(map, y, x + 1, turnips);
	solve(map, y - 1, x, turnips);
	solve(map, y, x - 1, turnips);
	return (exit);
}

char	**copy_map(t_map *map)
{
	int		i;
	int		j;
	char	**map_copy;

	i = 0;
	j = 0;
	map_copy = (char **)malloc((map->h + 1) * sizeof(char *));
	while (map->m[i] != NULL)
	{
		map_copy[i] = ft_strdup(map->m[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	path(t_map *map)
{
	t_map	map_copy;
	int		exit_found;

	map_copy.c_c = 0;
	map_copy.y = map->y;
	map_copy.x = map->x;
	map_copy.h = map->h;
	map_copy.m = copy_map(map);
	exit_found = solve(map_copy.m, map_copy.y, map_copy.x, &map_copy.c_c);
	free_map(&map_copy);
	if ((map_copy.c_c == map->t_c) && exit_found == 1)
		return (1);
	else
		return (0);
}
