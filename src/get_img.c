/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:26:23 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/22 10:21:34 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	error_image(t_game *game)
{
	if (game->textures.bob_f == NULL || game->textures.bob_l == NULL
		|| game->textures.bob_r == NULL || game->textures.exit == NULL
		|| game->textures.floor == NULL || game->textures.gary == NULL
		|| game->textures.wall == NULL || game->textures.jellyfish2 == NULL
		|| game->textures.jellyfish3 == NULL || game->textures.plankton == NULL
		|| game->textures.jellyfish1 == NULL)
		error(game, IMAGE_XPM_ERR);
}

void	set_textures(t_game *game)
{
	int	size;

	size = 64;
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, WALLL, &size, &size);
	game->textures.bob_f = mlx_xpm_file_to_image(game->mlx, BOBF, &size, &size);
	game->textures.bob_l = mlx_xpm_file_to_image(game->mlx, BOBL, &size, &size);
	game->textures.bob_r = mlx_xpm_file_to_image(game->mlx, BOBR, &size, &size);
	game->textures.gary = mlx_xpm_file_to_image(game->mlx, GARY, &size, &size);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, EXITT, &size, &size);
	game->textures.jellyfish1 = mlx_xpm_file_to_image(game->mlx,
			JELLYFISH1, &size, &size);
	game->textures.jellyfish2 = mlx_xpm_file_to_image(game->mlx,
			JELLYFISH2, &size, &size);
	game->textures.jellyfish3 = mlx_xpm_file_to_image(game->mlx,
			JELLYFISH3, &size, &size);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			FLOOR, &size, &size);
	game->textures.plankton = mlx_xpm_file_to_image(game->mlx,
			PLANKTON, &size, &size);
	error_image(game);
}
