/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:18:52 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/21 10:14:56 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		update_player_up(game);
	else if (key == A || key == LEFT)
		update_player_left(game);
	else if (key == S || key == DOWN)
		update_player_down(game);
	else if (key == D || key == RIGHT)
		update_player_right(game);
	return (1);
}

int	quit_game(t_game *game)
{
	printf("Closed game\n");
	destroy(game);
	return (1);
}

void	play(t_game *game)
{
	mlx_key_hook(game->window_mlx, key_press, game);
	mlx_hook(game->window_mlx, DestroyNotify, NoEventMask, quit_game, game);
	mlx_loop(game->mlx);
}
