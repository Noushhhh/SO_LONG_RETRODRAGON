/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:44:54 by aandric           #+#    #+#             */
/*   Updated: 2022/03/03 15:33:32 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(int fd, t_map *map)
{
	map->tmp_line = get_next_line(fd);
	if (!map->tmp_line)
		return (0);
	map->width = ft_linelen(map->tmp_line);
	map->onedim = ft_strdup(map->tmp_line);
	free(map->tmp_line);
	map->tmp_line = get_next_line(fd);
	while (map->tmp_line)
	{
		if (ft_linelen(map->tmp_line) != map->width)
		{
			write(2, "Error\nThe map is square like a dragon egg !!!\n", 47);
			return (0);
		}
		map->onedim = ft_strjoin(map->onedim, map->tmp_line);
		free(map->tmp_line);
		map->tmp_line = get_next_line(fd);
	}
	free(map->tmp_line);
	map->twodim = ft_split(map->onedim, '\n');
	if (!parse_map(&map))
		return (0);
	free(map->tmp_line);
	return (1);
}
