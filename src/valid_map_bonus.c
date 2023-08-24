/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:42:02 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/23 11:20:42 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	valid_form(t_game *game)
{
	int		len;
	int		index;

	len = game->map.columns;
	index = 0;
	while (game->map.map[index] != NULL)
	{
		if (ft_strlen(game->map.map[index]) != len)
			error(game, INVALID_FORMAT);
		index++;
	}
}

static void	error_elements(t_game *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		error(game, INVALID_NBR_EXITS);
	if (game->map.player == 0 || game->map.player > 1)
		error(game, INVALID_NBR_PLAYERS);
	if (game->map.collectibles == 0)
		error(game, NO_COLLECTIBLES);
}

static void	check_elements(t_game *game)
{
	int	index_l;
	int	index_c;

	index_l = 0;
	while (++index_l < game->map.lines)
	{
		index_c = 0;
		while (++index_c < game->map.columns)
		{
			if (ft_strchr("EPX01C", game->map.map[index_l][index_c]) == NULL)
				error(game, INVALID_ENTITY);
			if (game->map.map[index_l][index_c] == EXIT)
				game->map.exit += 1;
			if (game->map.map[index_l][index_c] == COLLECTIBLE)
				game->map.collectibles += 1;
			if (game->map.map[index_l][index_c] == PLAYER)
			{
				game->map.player += 1;
				game->map.player_pos.x = index_c;
				game->map.player_pos.y = index_l;
			}
		}
	}
	error_elements(game);
}

static void	is_closed(t_map *map, t_game *game)
{
	int	index_c;
	int	index_l;

	index_c = 0;
	index_l = 0;
	while (index_l < map->lines)
	{
		if (map->map[index_l][0] != WALL)
			error(game, MAP_NOT_CLOSED);
		if (map->map[index_l][map->columns - 1] != WALL)
			error(game, MAP_NOT_CLOSED);
		index_l++;
	}
	while (index_c < map->columns)
	{
		if (map->map[0][index_c] != WALL)
			error(game, MAP_NOT_CLOSED);
		if (map->map[map->lines - 1][index_c] != WALL)
			error(game, MAP_NOT_CLOSED);
		index_c++;
	}
}

void	map_is_valid(t_game *game)
{
	valid_form(game);
	check_elements(game);
	is_closed(&game->map, game);
	check_path(game);
}
