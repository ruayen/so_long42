/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissaou <raissaou@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 10:35:38 by raissaou          #+#    #+#             */
/*   Updated: 2025-02-14 10:35:38 by raissaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf(FILE_MSG));
	if (check_extension(argv[1]) == FALSE)
		return (ft_printf(FILE_EXT_MSG));
	game.map = read_map(argv[1]);
	if (!game.map)
		return (1);
	if (check_map(game.map) == FALSE)
		return (free_map(game.map), 1);
	size_map(&game, game.map);
	if (valid_path(&game, argv[1]) == FALSE)
		return (free_map(game.map), 1);
	if (init_game(&game) == FALSE)
		return (1);
	return (0);
}
