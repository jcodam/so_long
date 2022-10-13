/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:13:38 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/13 18:22:54 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "char_list.h"

typedef struct s_data {
	void	*img;
	int		x;
	int		y;
}				t_data;

typedef struct s_player{
	int		name;
	int		y;
	int		x;
	int		sluge;
	void	*img;
	void	*img2;
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
	int			map_x;
	int			map_y;
}				t_vars;

t_clist	*make_map(char **argv);
void	put_map(t_vars *vars, int space);

#endif