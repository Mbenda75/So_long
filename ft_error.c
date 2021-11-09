/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:33:35 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/09 20:34:01 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(int error)
{
	if (error == 1)
	{
		printf("Error, WRONG SIZE OF THE MAP\n");
		exit(1);
	}
	else if (error == 2)
	{
		printf("Error, in the first wall of the map\n");
		exit(1);
	}
	else if (error == 3)
	{
		printf("Error, in the last wall of the map\n");
		exit(1);
	}
	else if (error == 4)
	{
		printf("Error, the map is not really close\n");
		exit(1);
	}
}

void	error_game(int err, t_game game)
{
	if (err == 1)
	{
		printf("Error, the map is not valid, wrong element\n");
		exit(1);
	}
	else if (err == 2)
	{
		if (game.player > 1)
		{
			printf("Error, we have more than 1 player\n");
			exit(1);
		}
		else if (game.exi < 1 || game.coin < 1 || game.player < 1)
		{
			printf(" e = %d\n c = %d\n p = %d\n", game.exi, game.coin, game.player);
			printf("Error, one element is missing\n");
			exit(1);
		}
	}
}

void	error_arg(int ac, char **av, int fd)
{
	int	i;

	(void)ac;
	i = 0;
	if (fd == -1)
	{
		printf("Error, enter a valid file\n");
		exit(1);
	}
	i = ft_strlen(av[1]);
	i--;
	if (av[1][i] != 'r' || av[1][i - 1] != 'e' || av[1][i - 2] != 'b' ||
		av[1][i - 3] != '.')
	{
		printf("Error, the map is not a .ber map\n");
		exit(1);
	}
	return ;
}
