/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:25:12 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/21 13:37:54 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// INCLUDES
# include <stdio.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "libft.h"
# include "error_messages.h"

// TEXTURES
# define WALLL "./src/textures/wall.xpm"
# define BOBF "./src/textures/bob_f.xpm"
# define BOBL "./src/textures/bob_l.xpm"
# define BOBR "./src/textures/bob_r.xpm"
# define EXITT "./src/textures/exit.xpm"
# define FLOOR "./src/textures/floor.xpm"
# define GARY "./src/textures/gary.xpm"
# define JELLYFISH1 "./src/textures/jellyfish1.xpm"
# define JELLYFISH2 "./src/textures/jellyfish2.xpm"
# define JELLYFISH3 "./src/textures/jellyfish3.xpm"
# define PLANKTON "./src/textures/plankton.xpm"

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_map {
	char			**map;
	int				lines;
	int				columns;
	int				collectibles;
	int				exit;
	int				player;
	t_point			player_pos;
}				t_map;

typedef struct s_textures {
	void	*wall;
	void	*floor;
	void	*bob_f;
	void	*bob_l;
	void	*bob_r;
	void	*plankton;
	void	*gary;
	void	*jellyfish1;
	void	*jellyfish2;
	void	*jellyfish3;
	void	*exit;
}				t_textures;

typedef struct s_game {
	t_map			map;
	void			*mlx;
	void			*window_mlx;
	t_textures		textures;
	int				moves;
}					t_game;

// GAME OBJECTS KEYS
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'
# define ENEMY 'X'

// GAME KEYWORDS
# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

# define ESC 65307

//                                                    ***FUNCTIONS***

// MAIN FUNCION
void	get_map(char *map_file, t_game *game);
void	map_is_valid(t_game *game);
int		args_is_valid(int argc, char **argv);
void	check_path(t_game *game);
void	free_map(char **map, t_game *game);
void	init_game(t_game *game);
void	render_map(t_game *game, char position);
void	render_obj(t_game *game);
void	render_background(t_game *game);
void	render_player(t_game *game, char direction);
void	set_textures(t_game *game);
void	play(t_game *game);
int		key_press(int key, t_game *game);
int		quit_game(t_game *game);
void	won_game(t_game *game);
void	lost_game(t_game *game);
void	destroy_img(t_game *game);
void	destroy(t_game	*game);
void	update_player_up(t_game *game);
void	update_player_left(t_game *game);
void	update_player_down(t_game *game);
void	update_player_right(t_game *game);
void	error(t_game *game, char *error_msg);

#endif