/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:08:43 by lumedeir          #+#    #+#             */
/*   Updated: 2023/08/22 11:34:29 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

// ERROR MESSAGES
# define MALLOC_ERR "malloc() failed"
# define INIT_ERR "Failed to initialize mlx"
# define NEW_WINDOW_ERR "Failed to open a new window"

// arguments validation
# define INVALID_NBR_ARGS "Invalid number of arguments" 

// Map validation
# define INVALID_ENTITY "Invalid entity on map's file"
# define INVALID_FORMAT "Invalid map format"
# define MAP_NOT_CLOSED "Map should be closed by walls"
# define INVALID_NBR_EXITS "Invalid number of Exits (E)"
# define NO_COLLECTIBLES "Map doesn't have any Collectible (C)"
# define INVALID_NBR_PLAYERS "Invalid number of Starting Positions (P)"
# define UNACHIEVABLE_ENTITIES "Map has no valid path"

// Reading map's
# define INVALID_MAP_FILE "Invalid map file extension"
# define OPEN_MAP_FILE_ERR "Failed to open map's file"
# define EMPTY_MAP_FILE "Map file is empty"

// XPM Open
# define IMAGE_XPM_ERR "Failed to open image .XPM"

#endif