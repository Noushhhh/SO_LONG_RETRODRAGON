/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:42:48 by aandric           #+#    #+#             */
/*   Updated: 2022/03/03 15:38:27 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_surrounded(t_map **map)
{
	int	x;
	int	y;

	x = 0;
	(*map)->width = ft_strlen((*map)->twodim[x]) - 1;
	(*map)->height = ft_split_len((*map)->twodim) - 1;
	while ((*map)->twodim[x])
	{
		y = 0;
		while ((*map)->twodim[x][y])
		{
			if (x == 0 && (*map)->twodim[x][y] != '1')
				return (0);
			if (y == 0 && (*map)->twodim[x][y] != '1')
				return (0);
			if (y == (*map)->width && (*map)->twodim[x][y] != '1')
				return (0);
			if (x == (*map)->height && (*map)->twodim[x][y] != '1')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	valid_cells(t_map **map)
{
	int	x;
	int	y;

	x = 0;
	while ((*map)->twodim[x])
	{
		y = 0;
		while ((*map)->twodim[x][y])
		{
			if ((*map)->twodim[x][y] == 'C')
				(*map)->collec++;
			if ((*map)->twodim[x][y] == 'E')
				(*map)->exit++;
			if ((*map)->twodim[x][y] == 'P')
				(*map)->startpos++;
			if (((*map)->twodim[x][y] != 'C') && ((*map)->twodim[x][y] != 'E')
				&& ((*map)->twodim[x][y] != 'P') &&
				((*map)->twodim[x][y] != '1') && ((*map)->twodim[x][y] != '0'))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	parse_map(t_map **map)
{
	if (!is_surrounded(map))
	{
		write(2, "Error\nNot enough palmtrees around this pink water !!!\n", 55);
		return (0);
	}
	if (!valid_cells(map))
	{
		write(2, "Error\nBiiiiip, unvalid cells in the map !!!\n", 45);
		return (0);
	}
	if ((*map)->collec < 1 || (*map)->exit < 1 || (*map)->startpos != 1)
	{
		write(2, "Error\nSomething is missing in the map...\n", 43);
		return (0);
	}
	return (1);
}
