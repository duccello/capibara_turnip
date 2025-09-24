/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypresses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:03:22 by duccello          #+#    #+#             */
/*   Updated: 2025/07/14 19:03:25 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_ptr *ptr, t_map *map)
{
	int	n_y;

	n_y = map->y;
	n_y--;
	if (map->m[n_y][map->x] == '0' || map->m[n_y][map->x] == 'C'
		|| (map->m[n_y][map->x] == 'E' && map->c_c == map->t_c))
	{
		if (map->m[n_y][map->x] == 'C')
			map->c_c++;
		if (map->m[n_y][map->x] == 'E')
		{
			map->c_m++;
			ft_printf("Game complete!\nFinal Score: %i\n", map->c_m);
			mlx_loop_end(ptr->min);
			return ;
		}
		map->m[n_y][map->x] = 'P';
		map->m[map->y][map->x] = '0';
		ptr->img.capy = ptr->img.capy_u;
		render(ptr->min, ptr->win, &ptr->img, map);
		map->y = n_y;
		map->c_m++;
		ft_printf("%i\n", ptr->map.c_m);
	}
}

void	move_down(t_ptr *ptr, t_map *map)
{
	int	n_y;

	n_y = map->y;
	n_y++;
	if (map->m[n_y][map->x] == '0' || map->m[n_y][map->x] == 'C'
		|| (map->m[n_y][map->x] == 'E' && map->c_c == map->t_c))
	{
		if (map->m[n_y][map->x] == 'C')
			map->c_c++;
		if (map->m[n_y][map->x] == 'E')
		{
			map->c_m++;
			ft_printf("Game complete!\nFinal Score: %i\n", map->c_m);
			mlx_loop_end(ptr->min);
			return ;
		}
		map->m[n_y][map->x] = 'P';
		map->m[map->y][map->x] = '0';
		ptr->img.capy = ptr->img.capy_d;
		render(ptr->min, ptr->win, &ptr->img, map);
		map->y = n_y;
		map->c_m++;
		ft_printf("%i\n", ptr->map.c_m);
	}
}

void	move_left(t_ptr *ptr, t_map *map)
{
	int	n_x;

	n_x = map->x;
	n_x--;
	if (map->m[map->y][n_x] == '0' || map->m[map->y][n_x] == 'C'
		|| (map->m[map->y][n_x] == 'E' && map->c_c == map->t_c))
	{
		if (map->m[map->y][n_x] == 'C')
			map->c_c++;
		if (map->m[map->y][n_x] == 'E')
		{
			map->c_m++;
			ft_printf("Game complete!\nFinal Score: %i\n", map->c_m);
			mlx_loop_end(ptr->min);
			return ;
		}
		map->m[map->y][n_x] = 'P';
		map->m[map->y][map->x] = '0';
		ptr->img.capy = ptr->img.capy_l;
		render(ptr->min, ptr->win, &ptr->img, map);
		map->x = n_x;
		map->c_m++;
		ft_printf("%i\n", ptr->map.c_m);
	}
}

void	move_right(t_ptr *ptr, t_map *map)
{
	int	n_x;

	n_x = map->x;
	n_x++;
	if (map->m[map->y][n_x] == '0' || map->m[map->y][n_x] == 'C'
		|| (map->m[map->y][n_x] == 'E' && map->c_c == map->t_c))
	{
		if (map->m[map->y][n_x] == 'C')
			map->c_c++;
		if (map->m[map->y][n_x] == 'E')
		{
			map->c_m++;
			ft_printf("Game complete!\nFinal Score: %i\n", map->c_m);
			mlx_loop_end(ptr->min);
			return ;
		}
		map->m[map->y][n_x] = 'P';
		map->m[map->y][map->x] = '0';
		ptr->img.capy = ptr->img.capy_r;
		render(ptr->min, ptr->win, &ptr->img, map);
		map->x = n_x;
		map->c_m++;
		ft_printf("%i\n", ptr->map.c_m);
	}
	return ;
}

int	key_p(int keysym, t_ptr *ptr)
{
	if (keysym == XK_Escape)
		quit(ptr);
	if (keysym == XK_Up || keysym == XK_w || keysym == XK_W)
		move_up(ptr, &ptr->map);
	if (keysym == XK_Down || keysym == XK_s || keysym == XK_S)
		move_down(ptr, &ptr->map);
	if (keysym == XK_Left || keysym == XK_a || keysym == XK_a)
		move_left(ptr, &ptr->map);
	if (keysym == XK_Right || keysym == XK_d || keysym == XK_D)
		move_right(ptr, &ptr->map);
	return (0);
}
