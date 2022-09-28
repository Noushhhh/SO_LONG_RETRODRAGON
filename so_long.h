/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:45:03 by aandric           #+#    #+#             */
/*   Updated: 2022/03/03 15:29:22 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SIZE_IMG 100
# define RIGHT_KC 2
# define LEFT_KC 0
# define UP_KC 13
# define DOWN_KC 1
# define ESCAPE_KC 53
# define PATH_BG "./imgs/xpm/pink_water.xpm"
# define PATH_WALLS "./imgs/xpm/PalmTree.xpm"
# define PATH_COLLEC "./imgs/xpm/watermelon.xpm"
# define PATH_P_R "./imgs/xpm/dragon_right.xpm"
# define PATH_P_L "./imgs/xpm/dragon_left.xpm"
# define PATH_P_U "./imgs/xpm/dragon_up.xpm"
# define PATH_P_D "./imgs/xpm/dragon_down.xpm"
# define PATH_E1 "./imgs/xpm/typhoon_1.xpm"
# define PATH_E2 "./imgs/xpm/typhoon_2.xpm"
# define PATH_E3 "./imgs/xpm/typhoon_3.xpm"
# define PATH_E4 "./imgs/xpm/typhoon_3.xpm"

# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef struct s_map
{
	char	*tmp_line;
	int		tmp_width;
	int		height;
	int		width;
	int		x_exit;
	int		y_exit;
	char	*onedim;
	char	**twodim;
	int		collec;
	int		exit;
	int		startpos;
	int		time;
}			t_map;

typedef struct s_pers
{
	int		x;
	int		y;
	int		collec;
	int		i_steps_count;
	char	*steps_count;
}			t_pers;

typedef struct s_sprites
{
	void	*mlx;
	void	*win;
	void	*walls;
	void	*backg;
	void	*pers_d;
	void	*pers_r;
	void	*pers_l;
	void	*pers_u;
	void	*pers_last;
	void	*collec;
	void	*exit_1;
	void	*exit_2;
	void	*exit_3;
	void	*exit_4;
	int		sprte_size;
}			t_sprites;

typedef struct s_data
{
	t_sprites	sprites;
	t_map		map;
	t_pers		pers;
}				t_data;

/*so_long*/

int		so_long(int fd);
void	init_map(t_map *map, t_sprites *sprites, t_pers *pers);
void	get_sprites(t_map *map, t_sprites *sprites);
void	put_background(t_map *map, t_sprites *sprites, t_pers *pers);
void	put_collec_exit(t_map *map, t_sprites *sprites, t_pers *pers);
int		get_events(int keycode, t_data *data);
void	move_pers(int keycode, t_pers *pers, t_map *map, t_sprites *sprites);
void	move_right(t_pers *pers, t_map *map, t_sprites *sprites);
void	move_left(t_pers *pers, t_map *map, t_sprites *sprites);
void	move_up(t_pers *pers, t_map *map, t_sprites *sprites);
void	move_down(t_pers *pers, t_map *map, t_sprites *sprites);
int		move_typhoon(t_data *data);

/*utils*/

int		get_map(int fd, t_map *map);
int		is_square(t_map **map);
int		parse_map(t_map **map);
int		is_surrounded(t_map **map);
void	put_steps(t_map *map, t_pers *pers, t_sprites *sprites);
int		ft_close(t_data *data);

#endif
