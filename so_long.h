/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 11:39:32 by raissaou          #+#    #+#             */
/*   Updated: 2025-02-03 11:39:32 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <memory.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>

# define MAP_EXIT 'E'
# define MAP_WALL '1'
# define MAP_FLOOR '0'
# define MAP_COLLECTOR 'C'
# define MAP_START 'P'

# define BUFF_SIZE	10000
# define FALSE			1
# define TRUE			0
# define MOVE			32

# define FILE_MSG "Error\nIntroduce only 2 parametres, thank you \n"
# define FILE_EXT_MSG "Error\nFile Not Valid, please retry\n"
# define EMPTY_MAP_MSG "Error\nThe map is empty :-(\n"
# define RECT_MAP_MSG "Error\nThe map should be a rectangle\n"
# define WRONG_MAP_MSG "Error\nThe map has wrong components\n"
# define WALL_ERROR_MSG "Error\n The walls of the maps are not closed\n"
# define MIN_TILES_MSG "Error\nYou don't have the correct components\n"
# define PATH_MSG "Error\nThere is not a valid path\n"

typedef struct textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*coin;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
}						t_textures;

typedef struct images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*coin;
	mlx_image_t	*player;
	mlx_image_t	*exit;
}						t_images;

typedef struct s_game
{
	t_textures				*textu;
	t_images				*imag;
	mlx_t					*mlx;
	char					**map;
	int						map_width;
	int						map_height;
	int						count_coin;
	int						count_moves;
	int						n_coin;
	char					**map2;
}										t_game;

char	**read_map(char *script_map);
void	free_map(char **map);
void	size_map(t_game *game, char **map);
int		check_extensions(const char *fn);
void	get_textures(t_game *game);
void	get_images(t_game *game);
void	draw_floor(t_game *game, t_images *image);
void	draw_map(t_game *game, t_images *image);
void	movements(mlx_key_data_t keydata, void *param);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);

#endif