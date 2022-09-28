/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:30:53 by aandric           #+#    #+#             */
/*   Updated: 2022/03/03 15:25:37 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	so_long(int fd)
{
	t_data		data;

	ft_memset(&data, 0, sizeof(t_data));
	data.pers.steps_count = ft_itoa(data.pers.i_steps_count);
	if (!get_map(fd, &data.map))
		ft_close(&data);
	init_map(&data.map, &data.sprites, &data.pers);
	mlx_hook(data.sprites.win, 2, 0, get_events, &data);
	mlx_hook(data.sprites.win, 17, 1L << 0, ft_close, &data);
	mlx_loop_hook(data.sprites.mlx, move_typhoon, &data);
	mlx_loop(data.sprites.mlx);
	free(data.map.onedim);
	return (0);
}
