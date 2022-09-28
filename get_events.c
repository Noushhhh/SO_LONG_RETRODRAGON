/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:00:47 by aandric           #+#    #+#             */
/*   Updated: 2022/03/03 15:36:19 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_events(int keycode, t_data *data)
{
	put_steps(&data->map, &data->pers, &data->sprites);
	if (keycode == ESCAPE_KC)
		ft_close(data);
	if (keycode == RIGHT_KC || keycode == LEFT_KC
		|| keycode == UP_KC || keycode == DOWN_KC)
	{
		move_pers(keycode, &data->pers, &data->map, &data->sprites);
		if (data->map.twodim[data->pers.y][data->pers.x] == 'E'
			&& data->pers.collec == 0)
		{
			write(2, "Yuuum, Watermelaaaa iz so good yaaa :))\n", 40);
			ft_close(data);
		}
	}
	return (0);
}
