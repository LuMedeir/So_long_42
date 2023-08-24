/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:09:00 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/22 13:41:05 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**copy_map(t_game *game)
{
	int		index;
	char	**copy;

	index = 0;
	copy = malloc((game->map.lines + 1) * sizeof(char *));
	if (!copy)
		error(game, MALLOC_ERR);
	while (index < game->map.lines)
	{
		copy[index] = ft_strdup(game->map.map[index]);
		if (!copy[index])
		{
			free_map(copy, game);
			error(game, MALLOC_ERR);
		}
		index++;
	}
	return (copy);
}

static bool	check_for_path(t_map *map, t_point position, char **copy)
{
	static int		coins = 0;
	static bool		found_exit = false;

	if (copy[position.y][position.x] == WALL ||
		copy[position.y][position.x] == ENEMY)
		return (false);
	else if (copy[position.y][position.x] == COLLECTIBLE)
		coins += 1;
	else if (copy[position.y][position.x] == EXIT)
		found_exit = true;
	copy[position.y][position.x] = WALL;
	check_for_path(map, (t_point){position.x + 1, position.y}, copy);
	check_for_path(map, (t_point){position.x - 1, position.y}, copy);
	check_for_path(map, (t_point){position.x, position.y + 1}, copy);
	check_for_path(map, (t_point){position.x, position.y - 1}, copy);
	return (coins == map->collectibles && found_exit);
}

void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < game->map.lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_path(t_game *game)
{
	char	**copy;

	copy = copy_map(game);
	if (!check_for_path(&game->map, game->map.player_pos, copy))
	{
		free_map(copy, game);
		error(game, UNACHIEVABLE_ENTITIES);
	}
	free_map(copy, game);
}
