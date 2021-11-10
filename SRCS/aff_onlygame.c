/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_onlygame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:34:41 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/09 21:22:37 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

void	aff_map(t_game game)
{
	aff_wall(game);
	aff_floor(game);
	aff_player(game);
	aff_coin(game);
	aff_exit(game);
}

t_game	dl_texture(t_game game)
{
	int	size;

	size = 64;
	game.wall = mlx_xpm_file_to_image(game.mlx,
			"./textures/wall-64t.xpm", &size, &size);
	game.img_player = mlx_xpm_file_to_image(game.mlx,
			"./textures/player-64.xpm", &size, &size);
	game.img_coin = mlx_xpm_file_to_image(game.mlx,
			"./textures/collectible-64.xpm", &size, &size);
	game.img_exi = mlx_xpm_file_to_image(game.mlx,
			"./textures/exit-64.xpm", &size, &size);
	game.floor = mlx_xpm_file_to_image(game.mlx,
			"./textures/bottom-64.xpm", &size, &size);
	return (game);
}

t_game	open_window(t_game game)
{
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.nb_char * 64,
			game.line * 64, "so_long");
	game = dl_texture(game);
	return (game);
}
