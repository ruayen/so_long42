/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 11:07:15 by raissaou          #+#    #+#             */
/*   Updated: 2025-02-17 11:07:15 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->imag->player->instances->y / 64 - 1]
		[game->imag->player->instances->x / 64] != MAP_WALL)
	{
		game->imag->player->instances->y -= MOVE;
		game->count_moves++;
		ft_printf("MOVES: %i\n", game->count_moves);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->imag->player->instances->y / 64 + 1]
		[game->imag->player->instances->x / 64] != MAP_WALL)
	{
		game->imag->player->instances->y += MOVE;
		game->count_moves++;
		ft_printf("MOVES: %i\n", game->count_moves);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->imag->player->instances->y / 64]
		[game->imag->player->instances->x / 64 - 1] != MAP_WALL)
	{
		game->imag->player->instances->x -= MOVE;
		game->count_moves++;
		ft_printf("MOVES: %i\n", game->count_moves);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->imag->player->instances->y / 64]
		[game->imag->player->instances->x / 64 + 1] != MAP_WALL)
	{
		game->imag->player->instances->x += MOVE;
		game->count_moves++;
		ft_printf("MOVES: %i\n", game->count_moves);
	}
}

void	movements(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	collec_coins(game);
}
