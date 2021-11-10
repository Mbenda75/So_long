/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:34:28 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/10 18:08:53 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

int	mouse_hook(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_coin);
	mlx_destroy_image(game->mlx, game->img_exi);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		free_all(*game);
		exit(EXIT_FAILURE);
	}
	if (keycode == 100)
		*game = right(*game);
	if (keycode == 97)
		*game = left(*game);
	if (keycode == 119)
		*game = up(*game);
	if (keycode == 115)
		*game = down(*game);
	return (0);
}

void	free_str(char **s)
{
	int	line;

	line = 0;
	while (s[line])
	{
		free(s[line]);
		line++;
	}
	free(s);
}

void	free_all(t_game game)
{
	int	i;

	i = 0;
	while (game.map[i])
		free(game.map[i++]);
	free(game.map);
	mlx_destroy_image(game.mlx, game.wall);
	mlx_destroy_image(game.mlx, game.img_player);
	mlx_destroy_image(game.mlx, game.img_coin);
	mlx_destroy_image(game.mlx, game.img_exi);
	mlx_destroy_image(game.mlx, game.floor);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}
