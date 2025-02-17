/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 09:16:52 by raissaou          #+#    #+#             */
/*   Updated: 2025-02-17 09:16:52 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_textures));
	game->textu->player = mlx_load_png("./images/luffy.png");
	game->textu->coin = mlx_load_png("./images/meat.png");
	game->textu->floor = mlx_load_png("./images/floor.png");
	game->textu->wall = mlx_load_png("./images/wall.png");
	game->textu->exit = mlx_load_png("./images/exit.png");
}

void	get_images(t_game *game)
{
	game->imag = ft_calloc(1, sizeof(t_images));
	game->imag->player = mlx_texture_to_image(game->mlx, game->textu->player);
	game->imag->coin = mlx_texture_to_image(game->mlx, game->textu->coin);
	game->imag->floor = mlx_texture_to_image(game->mlx, game->textu->floor);
	game->imag->wall = mlx_texture_to_image(game->mlx, game->textu->wall);
	game->imag->exit = mlx_texture_to_image(game->mlx, game->textu->exit);
	mlx_delete_texture(game->textu->floor);
	mlx_delete_texture(game->textu->wall);
	mlx_delete_texture(game->textu->coin);
	mlx_delete_texture(game->textu->player);
	mlx_delete_texture(game->textu->exit);
}

void	draw_floor(t_game *game, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game -> map[y][x])
		{
			mlx_image_to_window(game->mlx, image->floor, x * 32, y * 32);
			if (game->map[y][x] == MAP_WALL)
				mlx_image_to_window(game->mlx, image->wall, x * 32, y * 32);
			if (game->map[y][x] == MAP_EXIT)
				mlx_image_to_window(game->mlx, image->exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game, t_images *image)
{
	int	x;
	int	y;

	draw_floor(game, image);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game -> map[y][x])
		{
			if (game->map[y][x] == MAP_COLLECTOR)
				mlx_image_to_window(game->mlx, image->coin, x * 32, y * 32);
			if (game->map[y][x] == MAP_START)
				mlx_image_to_window(game->mlx, image->player, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
