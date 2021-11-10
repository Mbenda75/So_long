/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:34:08 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/10 17:54:14 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/so_long.h"

int	count_line_map(char **str)
{
	int	line;

	line = 0;
	while (str[line])
		line++;
	return (line);
}

t_game	parsing(int fd)
{
	t_game	game;
	char	*map;
	char	*line;

	get_next_line(fd, &map);
	while (get_next_line(fd, &line) > 0)
	{
		map = ft_strcat(map, line);
		free(line);
	}
	map = ft_strcat(map, line);
	free(line);
	game.map = ft_split(map, '|');
	free(map);
	game.line = count_line_map(game.map);
	game.nb_char = ft_strlen(game.map[0]);
	check_size_linemap(game.map, game.line, game.nb_char);
	check_first_end(game.map, game.line - 1);
	check_wall_map(game.map, game.line - 1);
	game = check_inside_map(game.map, game.line - 1, game);
	return (game);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
		exit(1);
	fd = open(av[1], O_RDONLY);
	error_arg(ac, av, fd);
	game = parsing(fd);
	game = open_window(game);
	aff_map(game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, mouse_hook, &game);
	mlx_loop(game.mlx);
}
