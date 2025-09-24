/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:03:10 by duccello          #+#    #+#             */
/*   Updated: 2025/07/14 19:03:13 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(void *min, void *win, t_img *img, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			if (map->m[y][x] == '1')
				mlx_put_image_to_window(min, win, img->wall, x * 32, y * 32);
			if (map->m[y][x] == '0')
				mlx_put_image_to_window(min, win, img->grass, x * 32, y * 32);
			if (map->m[y][x] == 'E')
				mlx_put_image_to_window(min, win, img->pond, x * 32, y * 32);
			if (map->m[y][x] == 'C')
				mlx_put_image_to_window(min, win, img->food, x * 32, y * 32);
			if (map->m[y][x] == 'P')
				mlx_put_image_to_window(min, win, img->capy, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	init_image(t_ptr *ptr, t_img *img)
{
	int	w;
	int	h;

	img->capy_r = mlx_xpm_file_to_image(ptr->min, "./xpms/capy_r.xpm", &w, &h);
	img->capy_l = mlx_xpm_file_to_image(ptr->min, "./xpms/capy_l.xpm", &w, &h);
	img->capy_u = mlx_xpm_file_to_image(ptr->min, "./xpms/capy_u.xpm", &w, &h);
	img->capy_d = mlx_xpm_file_to_image(ptr->min, "./xpms/capy_d.xpm", &w, &h);
	img->food = mlx_xpm_file_to_image(ptr->min, "./xpms/food.xpm", &w, &h);
	img->wall = mlx_xpm_file_to_image(ptr->min, "./xpms/wall.xpm", &w, &h);
	img->grass = mlx_xpm_file_to_image(ptr->min, "./xpms/grass.xpm", &w, &h);
	img->pond = mlx_xpm_file_to_image(ptr->min, "./xpms/pond.xpm", &w, &h);
	img->capy = img->capy_r;
	render(ptr->min, ptr->win, img, &ptr->map);
}

int	readmap(t_map *map, char *file)
{
	char	*line;
	int		fd;
	int		i;
	int		len;

	i = 0;
	map->h = count_lines(file);
	map->m = (char **)malloc((map->h + 1) * sizeof(char *));
	fd = open(file, O_RDONLY);
	if (!map->m || fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->m[i++] = line;
		line = get_next_line(fd);
	}
	map->m[i] = NULL;
	close(fd);
	if (check_map(map) == 0)
		return (0);
	return (1);
}
