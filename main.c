/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:29:47 by aandric           #+#    #+#             */
/*   Updated: 2022/03/03 15:51:56 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(2, "Name of the map missing or too many arguments !\n", 49);
		return (0);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		write(2, "Not a .ber map :(\n", 18);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Unreadable file little bird :(\n", 31);
		return (0);
	}
	so_long(fd);
	close(fd);
	return (0);
}
