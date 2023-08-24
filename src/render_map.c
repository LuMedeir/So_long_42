/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:24:11 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/22 14:53:30 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_player(t_game *game, char direction)
{
	char	*moves_str;

	if (direction == 'u' || direction == 'd')
		mlx_put_image_to_window(game->mlx, game->window_mlx,
			game->textures.bob_f, 64 * game->map.player_pos.x,
			64 * game->map.player_pos.y);
	if (direction == 'l')
		mlx_put_image_to_window(game->mlx, game->window_mlx,
			game->textures.bob_l, 64 * game->map.player_pos.x,
			64 * game->map.player_pos.y);
	else if (direction == 'r')
		mlx_put_image_to_window(game->mlx, game->window_mlx,
			game->textures.bob_r, 64 * game->map.player_pos.x,
			64 * game->map.player_pos.y);
	moves_str = ft_itoa(game->moves);
	ft_printf("moves: %s\n", moves_str);
	free(moves_str);
}

void	render_background(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.lines)
	{
		x = -1;
		while (++x < game->map.columns)
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window_mlx,
					game->textures.wall, x * 64, y * 64);
			if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window_mlx,
					game->textures.floor, x * 64, y * 64);
		}
	}
}

void	render_obj(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.lines)
	{
		x = -1;
		while (++x < game->map.columns)
		{
			if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window_mlx,
					game->textures.jellyfish1, x * 64, y * 64);
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window_mlx,
					game->textures.exit, x * 64, y * 64);
		}
	}
}

void	render_map(t_game *game, char position)
{
	set_textures(game);
	render_background(game);
	render_player(game, position);
	render_obj(game);
}
