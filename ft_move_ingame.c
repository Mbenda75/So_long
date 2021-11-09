/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ingame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:33:50 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/08 16:33:52 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	moove_rightmap(t_game game)
{
	if (game.map[game.line][game.nb_char + 1] == 'C')
		game.coin--;
	if (game.map[game.line][game.nb_char + 1] == 'E'
			&& game.coin == 0)
	{
		game.nb_moove++;
		printf("nb_moove === %d\n", game.nb_moove);
		printf("END OF THE GAME");
		free_all(game);
		exit(0);
	}
	game.map[game.line][game.nb_char] = '0';
	game.map[game.line][game.nb_char + 1] = 'P';
	aff_map(game);
	game.nb_moove++;
	printf("nb_moove === %d\n", game.nb_moove);
	return (game);
}

t_game	moove_lefttmap(t_game game)
{
	if (game.map[game.line][game.nb_char - 1] == 'C')
		game.coin--;
	if (game.map[game.line][game.nb_char - 1] == 'E'
			&& game.coin == 0)
	{
		game.nb_moove++;
		printf("nb_moove === %d\n", game.nb_moove);
		printf("END OF THE GAME");
		free_all(game);
		exit(0);
	}
	game.map[game.line][game.nb_char] = '0';
	game.map[game.line][game.nb_char - 1] = 'P';
	aff_map(game);
	game.nb_moove++;
	printf("nb_moove === %d\n", game.nb_moove);
	return (game);
}

t_game	moove_upmap(t_game game)
{
	if (game.map[game.line - 1][game.nb_char] == 'C')
		game.coin--;
	if (game.map[game.line - 1][game.nb_char] == 'E'
			&& game.coin == 0)
	{
		game.nb_moove++;
		printf("nb_moove === %d\n", game.nb_moove);
		printf("END OF THE GAME");
		free_all(game);
		exit(0);
	}
	game.map[game.line][game.nb_char] = '0';
	game.map[game.line - 1][game.nb_char] = 'P';
	aff_map(game);
	game.nb_moove++;
	printf("nb_moove === %d\n", game.nb_moove);
	return (game);
}

t_game	moove_downmap(t_game game)
{
	if (game.map[game.line + 1][game.nb_char] == 'C')
		game.coin--;
	if (game.map[game.line + 1][game.nb_char] == 'E'
			&& game.coin == 0)
	{
		game.nb_moove++;
		printf("nb_moove === %d\n", game.nb_moove);
		printf("END OF THE GAME");
		free_all(game);
		exit(0);
	}
	game.map[game.line][game.nb_char] = '0';
	game.map[game.line + 1][game.nb_char] = 'P';
	aff_map(game);
	game.nb_moove++;
	printf("nb_moove === %d\n", game.nb_moove);
	return (game);
}
