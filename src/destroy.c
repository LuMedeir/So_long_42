/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:59:54 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/22 11:36:20 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error(t_game *game, char *error_msg)
{
	ft_printf("Error: %s\n", error_msg);
	destroy(game);
	return (1);
}

int	won_game(t_game *game)
{
	printf("Congratulations, you won!!! :)\n");
	destroy(game);
	return (1);
}

int	lost_game(t_game *game)
{
	printf("Too bad, you lost\n");
	destroy(game);
	return (1);
}

void	destroy_img(t_game *game)
{
	if (game->textures.bob_f != NULL)
		mlx_destroy_image(game->mlx, game->textures.bob_f);
	if (game->textures.bob_l != NULL)
		mlx_destroy_image(game->mlx, game->textures.bob_l);
	if (game->textures.bob_r != NULL)
		mlx_destroy_image(game->mlx, game->textures.bob_r);
	if (game->textures.wall != NULL)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.exit != NULL)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.gary != NULL)
		mlx_destroy_image(game->mlx, game->textures.gary);
	if (game->textures.jellyfish1 != NULL)
		mlx_destroy_image(game->mlx, game->textures.jellyfish1);
	if (game->textures.jellyfish2 != NULL)
		mlx_destroy_image(game->mlx, game->textures.jellyfish2);
	if (game->textures.jellyfish3 != NULL)
		mlx_destroy_image(game->mlx, game->textures.jellyfish3);
	if (game->textures.plankton != NULL )
		mlx_destroy_image(game->mlx, game->textures.plankton);
	if (game->textures.floor != NULL)
		mlx_destroy_image(game->mlx, game->textures.floor);
}

void	destroy(t_game	*game)
{
	if (!game)
		return ;
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->window_mlx);
	destroy_img(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map.map)
		free_map(game->map.map, game);
	exit(0);
}
