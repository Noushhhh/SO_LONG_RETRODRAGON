/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:28:58 by aandric           #+#    #+#             */
/*   Updated: 2022/03/03 15:48:18 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_data *data)
{
	int	x;

	if (data->sprites.mlx)
		mlx_destroy_window(data->sprites.mlx, data->sprites.win);
	x = 0;
	while (data->map.twodim && data->map.twodim[x])
	{
		free(data->map.twodim[x]);
		x++;
	}
	if (data->map.twodim)
		free(data->map.twodim);
	exit(0);
	return (0);
}

void	put_steps(t_map *map, t_pers *pers, t_sprites *sprites)
{
	(void)map;
	mlx_put_image_to_window(sprites->mlx, sprites->win,
		sprites->backg, 0, 0);
	mlx_put_image_to_window(sprites->mlx, sprites->win,
		sprites->walls, 0, 0);
	pers->i_steps_count++;
	if (pers->steps_count)
		free(pers->steps_count);
	pers->steps_count = ft_itoa(pers->i_steps_count);
	mlx_string_put(sprites->mlx, sprites->win, 50, 50, 0xFFFFFFFF,
		pers->steps_count);
}
