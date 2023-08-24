/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:29:12 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/21 09:44:12 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct(t_game *game)
{
	*game = (t_game){0};
	game->map.map = NULL;
	game->map.lines = 0;
	game->map.columns = 0;
	game->map.collectibles = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->textures.wall = NULL;
	game->textures.floor = NULL;
	game->textures.bob_f = NULL;
	game->textures.bob_l = NULL;
	game->textures.bob_r = NULL;
	game->textures.plankton = NULL;
	game->textures.gary = NULL;
	game->textures.jellyfish1 = NULL;
	game->textures.jellyfish2 = NULL;
	game->textures.jellyfish3 = NULL;
	game->textures.exit = NULL;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!args_is_valid(argc, argv))
		return (0);
	init_struct(&game);
	get_map(argv[1], &game);
	map_is_valid(&game);
	init_game(&game);
	render_map(&game, 'u');
	play(&game);
	return (0);
}
