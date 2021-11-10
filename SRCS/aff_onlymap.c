/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_onlymap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:11:13 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/10 15:11:15 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

void	aff_wall(t_game game)
{
	game.line = 0;
	game.nb_char = 0;
	while (game.map[game.line])
	{
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.wall,
					game.nb_char * 64, game.line * 64);
			game.nb_char++;
		}
		game.nb_char = 0;
		game.line++;
	}
}

void	aff_floor(t_game game)
{
	game.line = 0;
	game.nb_char = 0;
	while (game.map[game.line])
	{
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.floor,
					game.nb_char * 64, game.line * 64);
			game.nb_char++;
		}
		game.nb_char = 0;
		game.line++;
	}
}

void	aff_player(t_game game)
{
	game.line = 0;
	game.nb_char = 0;
	while (game.map[game.line])
	{
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.img_player,
					game.nb_char * 64, game.line * 64);
			game.nb_char++;
		}
		game.nb_char = 0;
		game.line++;
	}
}

void	aff_exit(t_game game)
{
	game.line = 0;
	game.nb_char = 0;
	while (game.map[game.line])
	{
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.img_exi,
					game.nb_char * 64, game.line * 64);
			game.nb_char++;
		}
		game.nb_char = 0;
		game.line++;
	}
}

void	aff_coin(t_game game)
{
	game.line = 0;
	game.nb_char = 0;
	while (game.map[game.line])
	{
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.img_coin,
					game.nb_char * 64, game.line * 64);
			game.nb_char++;
		}
		game.nb_char = 0;
		game.line++;
	}
}
