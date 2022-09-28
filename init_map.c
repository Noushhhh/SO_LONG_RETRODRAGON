/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:53:34 by aandric           #+#    #+#             */
/*   Updated: 2022/03/02 15:30:33 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map, t_sprites *sprites, t_pers *pers)
{
	sprites->mlx = mlx_init();
	sprites->win = mlx_new_window(sprites->mlx, (map->width + 1) * 100,
			(map->height + 1) * 100, "So_long");
	get_sprites(map, sprites);
	put_background(map, sprites, pers);
	put_collec_exit(map, sprites, pers);
}

void	get_sprites(t_map *map, t_sprites *sprites)
{
	(void)map;
	sprites->backg = mlx_xpm_file_to_image(sprites->mlx, PATH_BG,
			&sprites->sprte_size, &sprites->sprte_size);
	sprites->walls = mlx_xpm_file_to_image(sprites->mlx, PATH_WALLS,
			&sprites->sprte_size, &sprites->sprte_size);
	sprites->collec = mlx_xpm_file_to_image(sprites->mlx, PATH_COLLEC,
			&sprites->sprte_size, &sprites->sprte_size);
	sprites->pers_r = mlx_xpm_file_to_image(sprites->mlx, PATH_P_R,
			&sprites->sprte_size, &sprites->sprte_size);
	sprites->pers_l = mlx_xpm_file_to_image(sprites->mlx, PATH_P_L,
			&sprites->sprte_size, &sprites->sprte_size);
	sprites->pers_u = mlx_xpm_file_to_image(sprites->mlx, PATH_P_U,
			&sprites->sprte_size, &sprites->sprte_size);
	sprites->pers_d = mlx_xpm_file_to_image(sprites->mlx, PATH_P_D,
			&sprites->sprte_size, &sprites->sprte_size);
	sprites->exit_1 = mlx_xpm_file_to_image(sprites->mlx, PATH_E1,
			&sprites->sprte_size, &sprites->sprte_size);
	sprites->exit_2 = mlx_xpm_file_to_image(sprites->mlx, PATH_E2,
			&sprites->sprte_size, &sprites->sprte_size);
	sprites->exit_3 = mlx_xpm_file_to_image(sprites->mlx, PATH_E3,
			&sprites->sprte_size, &sprites->sprte_size);
	sprites->exit_4 = mlx_xpm_file_to_image(sprites->mlx, PATH_E4,
			&sprites->sprte_size, &sprites->sprte_size);
}

void	put_collec_exit(t_map *map, t_sprites *sprites, t_pers *pers)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->width + 1)
	{
		y = -1;
		while (++y < map->height + 1)
		{
			if (map->twodim[y][x] == 'C')
			{
				mlx_put_image_to_window(sprites->mlx, sprites->win,
					sprites->collec, x * SIZE_IMG, y * SIZE_IMG);
				pers->collec += 1;
			}
			if (map->twodim[y][x] == 'E')
			{
				mlx_put_image_to_window(sprites->mlx, sprites->win,
					sprites->exit_1, x * SIZE_IMG, y * SIZE_IMG);
				map->x_exit = x;
				map->y_exit = y;
			}
		}
	}
}

void	put_background(t_map *map, t_sprites *sprites, t_pers *pers)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->width + 1)
	{
		y = -1;
		while (++y < map->height + 1)
		{
			mlx_put_image_to_window(sprites->mlx, sprites->win,
				sprites->backg, x * SIZE_IMG, y * SIZE_IMG);
			if (map->twodim[y][x] == '1')
				mlx_put_image_to_window(sprites->mlx, sprites->win,
					sprites->walls, x * SIZE_IMG, y * SIZE_IMG);
			else if (map->twodim[y][x] == 'P')
			{
				mlx_put_image_to_window(sprites->mlx, sprites->win,
					sprites->pers_r, x * SIZE_IMG, y * SIZE_IMG);
				map->twodim[y][x] = '0';
				pers->x = x;
				pers->y = y;
			}
		}
	}
}

int	move_typhoon(t_data *data)
{
	int	x;
	int	y;

	x = data->map.x_exit;
	y = data->map.y_exit;
	data->map.time++;
	if (data->pers.x == x && data->pers.y == y)
		mlx_put_image_to_window(data->sprites.mlx, data->sprites.win,
			data->sprites.pers_last, x * SIZE_IMG, y * SIZE_IMG);
	if (data->map.time == 2000)
		mlx_put_image_to_window(data->sprites.mlx, data->sprites.win,
			data->sprites.exit_4, x * SIZE_IMG, y * SIZE_IMG);
	if (data->map.time == 4000)
		mlx_put_image_to_window(data->sprites.mlx, data->sprites.win,
			data->sprites.exit_2, x * SIZE_IMG, y * SIZE_IMG);
	if (data->map.time == 6000)
		mlx_put_image_to_window(data->sprites.mlx, data->sprites.win,
			data->sprites.exit_3, x * SIZE_IMG, y * SIZE_IMG);
	if (data->map.time == 8000)
		mlx_put_image_to_window(data->sprites.mlx, data->sprites.win,
			data->sprites.exit_1, x * SIZE_IMG, y * SIZE_IMG);
	if (data->map.time == 10000)
		data->map.time = 0;
	return (0);
}
