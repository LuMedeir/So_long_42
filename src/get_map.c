/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:56:29 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/22 14:34:36 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	args_is_valid(int argc, char **argv)
{
	int	len;

	len = ft_strlen(argv[1]) - 4;
	if (argc != 2)
	{
		ft_printf(INVALID_NBR_ARGS);
		return (0);
	}
	if (ft_strncmp(".ber", &argv[1][len], 4) != 0)
	{
		ft_printf(INVALID_MAP_FILE);
		return (0);
	}
	return (1);
}

static void	get_map_size(char *map_file, t_game *game)
{
	int		count_lines;
	int		map_fd;
	char	*temp;

	count_lines = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		error(game, OPEN_MAP_FILE_ERR);
	temp = get_next_line(map_fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(map_fd);
		count_lines++;
	}
	if (count_lines == 0)
		error(game, EMPTY_MAP_FILE);
	game->map.lines = count_lines;
	close(map_fd);
}

static void	read_map(char *map_file, t_game *game)
{
	int		map_fd;
	int		index;
	char	*temp;

	index = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		error(game, OPEN_MAP_FILE_ERR);
	while (index < game->map.lines)
		game->map.map[index++] = get_next_line(map_fd);
	temp = get_next_line(map_fd);
	free(temp);
	close(map_fd);
	index = 0;
	while (index < game->map.lines)
	{
		game->map.map[index] = ft_strtrim(game->map.map[index], "\n");
		if (!game->map.map[index])
			error(game, MALLOC_ERR);
		index++;
	}
	game->map.map[index] = NULL;
	game->map.columns = ft_strlen(game->map.map[0]);
}

void	get_map(char *map_file, t_game *game)
{
	get_map_size(map_file, game);
	game->map.map = malloc((game->map.lines + 1) * sizeof(char *));
	if (!game->map.map)
		error(game, MALLOC_ERR);
	read_map(map_file, game);
}
