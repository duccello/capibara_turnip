/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:09:16 by duccello          #+#    #+#             */
/*   Updated: 2025/07/03 11:09:18 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_image
{
	void	*capy;
	void	*capy_r;
	void	*capy_l;
	void	*capy_u;
	void	*capy_d;
	void	*wall;
	void	*food;
	void	*grass;
	void	*pond;
}			t_img;

typedef struct s_map
{
	int		w;
	int		h;
	char	**m;
	int		x;
	int		y;
	int		c_m;
	int		c_c;
	int		t_c;
}			t_map;

typedef struct s_pointer
{
	void	*min;
	void	*win;
	t_img	img;
	t_map	map;
}			t_ptr;

int			readmap(t_map *map, char *file);
int			key_p(int keysym, t_ptr *ptr);
void		render(void *min, void *win, t_img *img, t_map *map);
void		init_image(t_ptr *ptr, t_img *img);
int			quit(t_ptr *ptr);
int			count_lines(char *file);
int			position(t_map *map);
int			bounds(t_map *map);
int			check_map(t_map *map);
int			path(t_map *map);
int			collectibles(t_map *map);
void		free_map(t_map *map);

#endif