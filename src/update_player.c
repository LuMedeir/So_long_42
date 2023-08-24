/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:18:51 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/22 14:18:02 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_player_up(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	if (game->map.map[y - 1][x] == 'X' ||
		game->map.map[y - 1][x] == 'E' || game->map.map[y - 1][x] == '1')
	{
		if (game->map.map[y - 1][x] == 'X')
			lost_game(game);
		else if (game->map.map[y - 1][x] == 'E' && game->map.collectibles == 0)
			won_game(game);
		return ;
	}
	if (game->map.map[y - 1][x] == 'C')
		game->map.collectibles--;
	game->map.map[y][x] = '0';
	game->map.map[y - 1][x] = 'P';
	game->map.player_pos.y--;
	game->moves++;
	render_background(game);
	render_player(game, 'u');
}

void	update_player_left(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	if (game->map.map[y][x - 1] == 'X' ||
		game->map.map[y][x - 1] == 'E' || game->map.map[y][x - 1] == '1')
	{
		if (game->map.map[y][x - 1] == 'X')
			lost_game(game);
		else if (game->map.map[y][x - 1] == 'E' && game->map.collectibles == 0)
			won_game(game);
		return ;
	}
	if (game->map.map[y][x - 1] == 'C')
		game->map.collectibles--;
	game->map.map[y][x] = '0';
	game->map.map[y][x - 1] = 'P';
	game->map.player_pos.x--;
	game->moves++;
	render_background(game);
	render_player(game, 'l');
}

void	update_player_down(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	if (game->map.map[y + 1][x] == 'X' ||
		game->map.map[y + 1][x] == 'E' || game->map.map[y + 1][x] == '1')
	{
		if (game->map.map[y + 1][x] == 'X')
			lost_game(game);
		else if (game->map.map[y + 1][x] == 'E' && game->map.collectibles == 0)
			won_game(game);
		return ;
	}
	if (game->map.map[y + 1][x] == 'C')
		game->map.collectibles--;
	game->map.map[y][x] = '0';
	game->map.map[y + 1][x] = 'P';
	game->map.player_pos.y++;
	game->moves++;
	render_background(game);
	render_player(game, 'd');
}

void	update_player_right(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	if (game->map.map[y][x + 1] == 'X' ||
		game->map.map[y][x + 1] == 'E' || game->map.map[y][x + 1] == '1')
	{
		if (game->map.map[y][x + 1] == 'X')
			lost_game(game);
		else if (game->map.map[y][x + 1] == 'E' && game->map.collectibles == 0)
			won_game(game);
		return ;
	}
	if (game->map.map[y][x + 1] == 'C')
		game->map.collectibles--;
	game->map.map[y][x] = '0';
	game->map.map[y][x + 1] = 'P';
	game->map.player_pos.x++;
	game->moves++;
	render_background(game);
	render_player(game, 'r');
}
