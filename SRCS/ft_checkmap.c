#include "../INC/so_long.h"

void	check_wall_map(char **str, int line)
{
	int	i;
	int	nb_char;

	i = 1;
	while (i < line)
	{
		nb_char = ft_strlen((str[i])) - 1;
		if (str[i][0] != '1' || str[i][nb_char] != '1')
			error_map(4, str);
		i++;
	}
}

t_game	init(t_game game)
{
	game.nb_moove = 0;
	game.player = 0;
	game.coin = 0;
	game.exi = 0;
	return (game);
}

t_game	check_inside_map(char **str, int line, t_game game)
{
	int	i;

	i = 0;
	game = init(game);
	while (line > 0)
	{
		while (str[line][i])
		{
			if (str[line][i] == 'P')
				game.player++;
			else if (str[line][i] == 'C')
				game.coin++;
			else if (str[line][i] == 'E')
				game.exi++;
			if (str[line][i] != 'P' && str[line][i] != 'E' && str[line][i]
					!= 'C' && str[line][i] != '0' && str[line][i] != '1')
				error_game(1, game, str);
			i++;
		}
		i = 0;
		line--;
	}
	error_game(2, game, str);
	printf("La map est valide\n");
	return (game);
}

void	check_size_linemap(char **str, int line, int lenchar)
{
	int	i;
	int	count;

	i = 0;
	while (i < line)
	{
		count = ft_strlen(str[i]);
		if (count != lenchar)
			error_map(1, str);
		i++;
	}
}

void	check_first_end(char **str, int line)
{
	int	i;

	i = 0;
	while (str[0][i])
	{
		if (str[0][i] != '1')
			error_map(2, str);
		i++;
	}
	i = 0;
	while (str[line][i])
	{
		if (str[line][i] != '1')
			error_map(3, str);
		i++;
	}
}
