/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:33:29 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/09 20:57:49 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "./mlx/mlx.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*win;
	void		*img_player;
	void		*img_coin;
	void		*img_exi;
	void		*wall;
	void		*floor;
	int			nb_char;
	int			line;
	int			coin;
	int			player;
	int			exi;
	int			nb_moove;
}		t_game;

int			mouse_hook(t_game *game);
void		free_all(t_game game);
t_game		parsing(int fd);
int			count_line_map(char **str);
void		check_first_end(char **str, int line);
void		check_size_linemap(char **str, int line, int lenchar);
t_game		check_inside_map(char **str, int line, t_game game);
void		check_wall_map(char **str, int line);
char		*ft_strjoin_free(char *s1, char *s2);
int			boucle(char **stock, int fd, int ret);
int			get_next_line(int fd, char **line);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int			ft_strlen(const char *s);
char		*ft_strcat(char *dest, char *src);
char		**ft_split(char *str, char c);
t_game		open_window(t_game game);
t_game		dl_texture(t_game game);
int			key_hook(int keycode, t_game *game);
void		aff_map(t_game game);
void		aff_wall(t_game game);
void		aff_exit(t_game game);
void		aff_player(t_game game);
void		aff_coin(t_game game);
void		aff_floor(t_game game);
t_game		right(t_game game);
t_game		moove_rightmap(t_game game);
t_game		left(t_game game);
t_game		moove_lefttmap(t_game game);
t_game		up(t_game game);
t_game		moove_upmap(t_game game);
t_game		down(t_game game);
t_game		moove_downmap(t_game game);
void		error_map(int error);
void		error_game(int err, t_game game);
t_game		init(t_game game);
void		error_arg(int ac, char **av, int fd);

#endif
