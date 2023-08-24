/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:30:17 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/16 15:00:06 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, INIT_ERR);
	game->window_mlx = mlx_new_window(game->mlx, game->map.columns * 64,
			game->map.lines * 64, "Sponge Bob");
	if (!game->mlx)
		error(game, NEW_WINDOW_ERR);
}
