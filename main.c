/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:09:02 by duccello          #+#    #+#             */
/*   Updated: 2025/09/01 12:03:16 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->h)
	{
		free(map->m[i]);
		i++;
	}
	free(map->m);
}

void	free_images(t_ptr *ptr, t_img *img)
{
	mlx_destroy_image(ptr->min, img->capy_r);
	mlx_destroy_image(ptr->min, img->capy_l);
	mlx_destroy_image(ptr->min, img->capy_d);
	mlx_destroy_image(ptr->min, img->capy_u);
	mlx_destroy_image(ptr->min, img->food);
	mlx_destroy_image(ptr->min, img->wall);
	mlx_destroy_image(ptr->min, img->grass);
	mlx_destroy_image(ptr->min, img->pond);
}

int	quit(t_ptr *ptr)
{
	ft_printf("bye bye!\n");
	mlx_loop_end(ptr->min);
	return (0);
}

int	check_arg(int argc, char *name)
{
	int	len;

	len = ft_strlen(name);
	if (argc < 2 || argc > 2)
		return (0);
	if (ft_strncmp(name + (len - 4), ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_ptr	ptr;

	if (check_arg(argc, argv[1]) == 0)
	{
		ft_printf("Error\nI only operate with 1 .ber map\n");
		return (50);
	}
	if (readmap(&ptr.map, argv[1]) == 0)
		return (free_map(&ptr.map), ft_printf("Error\nInvalid map!\n"));
	ptr.min = mlx_init();
	if (ptr.min == NULL)
		return (ft_printf("Error\nmlx_init failed\n"));
	ptr.win = mlx_new_window(ptr.min, ptr.map.w * 32, ptr.map.h * 32,
			"capy->turnips->pond");
	if (ptr.win == NULL)
		return (0);
	init_image(&ptr, &ptr.img);
	mlx_hook(ptr.win, KeyPress, KeyPressMask, key_p, &ptr);
	mlx_hook(ptr.win, 17, 0, quit, &ptr);
	mlx_loop(ptr.min);
	free_images(&ptr, &ptr.img);
	free_map(&ptr.map);
	mlx_destroy_window(ptr.min, ptr.win);
	mlx_destroy_display(ptr.min);
	free(ptr.min);
	argc++;
	return (42);
}
