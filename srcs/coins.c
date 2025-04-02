/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-18 09:18:47 by raissaou          #+#    #+#             */
/*   Updated: 2025-02-18 09:18:47 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	total_coins(t_game *game)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				total++;
			j++;
		}
		i++;
	}
	return (total);
}

int	delete_coins(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = game->n_coin;
	while (i < count)
	{
		if (((game->imag->coin->instances[i].y
					== game->imag->player->instances->y)
				&& (game->imag->coin->instances[i].x
					== game->imag->player->instances->x))
			&& game->imag->coin->instances[i].enabled == true)
		{
			count--;
			game->imag->coin->instances[i].enabled = false;
			return (1);
		}
		i++;
	}
	return (0);
}

void	collec_coins(t_game *game)
{
	if (game->map[game->imag->player->instances->y / 64]
		[game->imag->player->instances->x / 64] == MAP_COLLECTOR)
	{
		delete_coins(game);
		game->map[game->imag->player->instances->y / 64]
		[game->imag->player->instances->x / 64] = MAP_FLOOR;
		game->count_coin++;
		if (game->count_coin == game->n_coin)
			game->imag->exit->instances->enabled = false;
	}
	if (game->map[game->imag->player->instances->y / 64]
		[game->imag->player->instances->x / 64] == MAP_EXIT)
	{
		if (game->count_coin == game->n_coin)
			mlx_close_window(game->mlx);
	}
}
