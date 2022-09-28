/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:31:09 by aandric           #+#    #+#             */
/*   Updated: 2022/03/02 15:32:31 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_pers(int keycode, t_pers *pers, t_map *map, t_sprites *sprites)
{
	if (keycode == RIGHT_KC)
		move_right(pers, map, sprites);
	else if (keycode == LEFT_KC)
		move_left(pers, map, sprites);
	else if (keycode == UP_KC)
		move_up(pers, map, sprites);
	else if (keycode == DOWN_KC)
		move_down(pers, map, sprites);
}

void	move_right(t_pers *pers, t_map *map, t_sprites *sprites)
{
	if (map->twodim[pers->y][pers->x + 1] == '1')
		return ;
	else
	{
		pers->x += 1;
		if (map->twodim[pers->y][pers->x] == 'C')
		{
			map->twodim[pers->y][pers->x] = '0';
			pers->collec--;
			mlx_put_image_to_window(sprites->mlx, sprites->win,
				sprites->backg, pers->x * SIZE_IMG, pers->y
				* SIZE_IMG);
		}
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->pers_r,
			pers->x * SIZE_IMG, pers->y * SIZE_IMG);
		if (map->twodim[pers->y][pers->x - 1] != 'E')
			mlx_put_image_to_window(sprites->mlx, sprites->win,
				sprites->backg, (pers->x - 1) * SIZE_IMG, pers->y * SIZE_IMG);
		if (map->twodim[pers->y][pers->x - 1] == 'E')
			mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->exit_1,
				(pers->x - 1) * SIZE_IMG, pers->y * SIZE_IMG);
	}
	sprites->pers_last = mlx_xpm_file_to_image(sprites->mlx, PATH_P_R,
			&sprites->sprte_size, &sprites->sprte_size);
}

void	move_left(t_pers *pers, t_map *map, t_sprites *sprites)
{
	if (map->twodim[pers->y][pers->x - 1] == '1')
		return ;
	else
	{
		pers->x -= 1;
		if (map->twodim[pers->y][pers->x] == 'C')
		{	
			map->twodim[pers->y][pers->x] = '0';
			pers->collec--;
			mlx_put_image_to_window(sprites->mlx, sprites->win,
				sprites->backg, pers->x * SIZE_IMG,
				pers->y * SIZE_IMG);
		}
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->pers_l,
			pers->x * SIZE_IMG, pers->y * SIZE_IMG);
		if (map->twodim[pers->y][pers->x + 1] != 'E')
			mlx_put_image_to_window(sprites->mlx, sprites->win,
				sprites->backg, (pers->x + 1) * SIZE_IMG, pers->y * SIZE_IMG);
		if (map->twodim[pers->y][pers->x + 1] == 'E')
			mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->exit_1,
				(pers->x + 1) * SIZE_IMG, pers->y * SIZE_IMG);
	}
	sprites->pers_last = mlx_xpm_file_to_image(sprites->mlx, PATH_P_L,
			&sprites->sprte_size, &sprites->sprte_size);
}

void	move_down(t_pers *pers, t_map *map, t_sprites *sprites)
{
	if (map->twodim[pers->y + 1][pers->x] == '1')
		return ;
	else
	{
		pers->y += 1;
		if (map->twodim[pers->y][pers->x] == 'C')
		{
			map->twodim[pers->y][pers->x] = '0';
			pers->collec--;
			mlx_put_image_to_window(sprites->mlx, sprites->win,
				sprites->backg, pers->x * SIZE_IMG, pers->y
				* SIZE_IMG);
		}
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->pers_d,
			pers->x * SIZE_IMG, pers->y * SIZE_IMG);
		if (map->twodim[pers->y - 1][pers->x] != 'E')
			mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->backg,
				pers->x * SIZE_IMG, (pers->y - 1) * SIZE_IMG);
		if (map->twodim[pers->y - 1][pers->x] == 'E')
			mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->exit_1,
				pers->x * SIZE_IMG, (pers->y - 1) * SIZE_IMG);
	}
	sprites->pers_last = mlx_xpm_file_to_image(sprites->mlx, PATH_P_D,
			&sprites->sprte_size, &sprites->sprte_size);
}

void	move_up(t_pers *pers, t_map *map, t_sprites *sprites)
{
	if (map->twodim[pers->y - 1][pers->x] == '1')
		return ;
	else
	{
		pers->y -= 1;
		if (map->twodim[pers->y][pers->x] == 'C')
		{
			map->twodim[pers->y][pers->x] = '0';
			pers->collec--;
			mlx_put_image_to_window(sprites->mlx, sprites->win,
				sprites->backg, pers->x * SIZE_IMG,
				pers->y * SIZE_IMG);
		}
		mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->pers_u,
			pers->x * SIZE_IMG, pers->y * SIZE_IMG);
		if (map->twodim[pers->y + 1][pers->x] != 'E')
			mlx_put_image_to_window(sprites->mlx, sprites->win,
				sprites->backg, pers->x * SIZE_IMG, (pers->y + 1) * SIZE_IMG);
		if (map->twodim[pers->y + 1][pers->x] == 'E')
			mlx_put_image_to_window(sprites->mlx, sprites->win, sprites->exit_1,
				pers->x * SIZE_IMG, (pers->y + 1) * SIZE_IMG);
	}
	sprites->pers_last = mlx_xpm_file_to_image(sprites->mlx, PATH_P_U,
			&sprites->sprte_size, &sprites->sprte_size);
}
