/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:13:38 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/19 15:40:10 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include "char_list.h"
# include "../printf/ft_printf.h"

typedef struct s_data {
	void	*img;
	int		x;
	int		y;
}				t_data;

typedef struct s_map {
	int			map_c;
	int			map_p;
	int			map_e;
}				t_map;

typedef struct s_player{
	int		y;
	int		x;
	int		sluge;
	int		steps;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img_l;
	void	*img_r;
}				t_player;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_data		*pit;
	t_data		*wall;
	t_data		*floor;
	t_data		*collect;
	t_player	*exit;
	t_player	*play;
	t_clist		*map;
	char		*string;
	int			map_x;
	int			map_y;
}				t_vars;

t_clist	*make_map(char **argv);
void	put_map(t_vars *vars, int space);
void	check_map(t_clist *map, t_vars *vars);
void	map_exit(char *str);
int		exit_pro(t_vars *vars);
void	find_error(t_map *cep, int i, int x);
void	_ber(char *arg);

#endif