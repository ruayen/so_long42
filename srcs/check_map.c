/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-18 10:54:55 by raissaou          #+#    #+#             */
/*   Updated: 2025-02-18 10:54:55 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	empty_map(char **map)
{
	if (map[0])
		return (TRUE);
	else
		return (FALSE);
}

int	rectangle_map(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (FALSE);
		else
			i++;
	}
	return (TRUE);
}

int	wrong_map(char **map)
{
	int	i;
	int	o;

	i = 0;
	while (map[i])
	{
		o = 0;
		while (map[i][o])
		{
			if (!(map[i][o] == MAP_EXIT || map[i][o] == MAP_START
				|| map[i][o] == MAP_WALL || map[i][o] == MAP_FLOOR
				|| (map[i][o] == MAP_COLLECTOR)))
				return (FALSE);
			else
				o++;
		}
		i++;
	}
	return (TRUE);
}

int	wall_map(char **map)
{
	size_t	i;
	size_t	o;
	size_t	line;

	line = 0;
	while (map[line])
		line++;
	i = 0;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[line - 1][i] != '1')
			return (FALSE);
		i++;
	}
	o = 0;
	while (i < (line - 1))
	{
		if (map[o][0] != '1' || map[ft_strlen(map[0])][0] != '1')
			return (FALSE);
		o++;
	}
	return (TRUE);
}

int	check_map(char **map)
{
	if (empty_map(map) == FALSE)
		return (ft_printf(EMPTY_MAP_MSG), FALSE);
	if (rectangle_map(map) == FALSE)
		return (ft_printf(RECT_MAP_MSG), FALSE);
	if (wrong_map(map) == FALSE)
		return (ft_printf(WRONG_MAP_MSG), FALSE);
	if (wall_map(map) == FALSE)
		return (ft_printf(WALL_ERROR_MSG), FALSE);
	if (min_tiles(map) == FALSE)
		return (ft_printf(MIN_TILES_MSG), FALSE);
	return (TRUE);
}
