/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:33:58 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/09 20:05:30 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	right(t_game game)
{
	game.line = 0;
	while (game.map[game.line])
	{
		game.nb_char = 0;
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'P')
			{
				if (game.map[game.line][game.nb_char + 1] == '1')
					return (game);
				if (game.map[game.line][game.nb_char + 1] == 'E' &&
						game.coin != 0)
					return (game);
				game = moove_rightmap(game);
				return (game);
			}
			game.nb_char++;
		}
		game.line++;
	}
	return (game);
}

t_game	left(t_game game)
{
	game.line = 0;
	while (game.map[game.line])
	{
		game.nb_char = 0;
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'P')
			{
				if (game.map[game.line][game.nb_char - 1] == '1')
					return (game);
				if (game.map[game.line][game.nb_char - 1] == 'E'
						&& game.coin != 0)
					return (game);
				game = moove_lefttmap(game);
				return (game);
			}
			game.nb_char++;
		}
		game.line++;
	}
	return (game);
}

t_game	up(t_game game)
{
	game.line = 0;
	while (game.map[game.line])
	{
		game.nb_char = 0;
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'P')
			{
				if (game.map[game.line - 1][game.nb_char] == '1')
					return (game);
				if (game.map[game.line - 1][game.nb_char] == 'E'
						&& game.coin != 0)
					return (game);
				game = moove_upmap(game);
				return (game);
			}
			game.nb_char++;
		}
		game.line++;
	}
	return (game);
}

t_game	down(t_game game)
{
	game.line = 0;
	while (game.map[game.line])
	{
		game.nb_char = 0;
		while (game.map[game.line][game.nb_char])
		{
			if (game.map[game.line][game.nb_char] == 'P')
			{
				if (game.map[game.line + 1][game.nb_char] == '1')
					return (game);
				if (game.map[game.line + 1][game.nb_char] == 'E'
						&& game.coin != 0)
					return (game);
				game = moove_downmap(game);
				return (game);
			}
			game.nb_char++;
		}
		game.line++;
	}
	return (game);
}
