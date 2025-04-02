/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-21 09:31:36 by raissaou          #+#    #+#             */
/*   Updated: 2025-02-21 09:31:36 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	min_tiles(char **map)
{
	int	i;
	int	j;
	int	n_exit_player;
	int	n_coin;

	i = 0;
	n_exit_player = 0;
	n_coin = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_EXIT || map[i][j] == MAP_START)
				n_exit_player++;
			if (map[i][j] == MAP_COLLECTOR)
				n_coin++;
			j++;
		}
		i++;
	}
	if (n_exit_player != 2 || n_coin < 0)
		return (FALSE);
	return (TRUE);
}

int	*start_pos(char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = (int *)ft_calloc(2, sizeof(int));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == MAP_EXIT)
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	flood_map(t_game *game, int y, int x)
{
	if (!(x < 1 || y < 1 || x >= game->map_width || y >= game->map_height
			|| game->map2[y][x] == '1' || game->map2[y][x] == 'X'))
	{
		game->map2[y][x] = 'X';
		flood_map(game, y + 1, x);
		flood_map(game, y - 1, x);
		flood_map(game, y, x + 1);
		flood_map(game, y, x - 1);
	}
}

int	check_flood(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == MAP_WALL || map[i][j] == MAP_FLOOR
				|| map[i][j] == 'X'))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	valid_path(t_game *game, char *fd)
{
	int	*pos;

	game->map2 = read_map(fd);
	pos = start_pos(game->map2);
	flood_map(game, pos[0], pos[1]);
	if (check_flood(game->map2) == FALSE)
	{
		free(pos);
		free_map(game->map2);
		return (ft_printf(PATH_MSG), FALSE);
	}
	free(pos);
	free_map(game->map2);
	return (TRUE);
}
