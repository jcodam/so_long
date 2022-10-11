/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:04:13 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/11 19:17:23 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aloc_vars(t_vars *vars)
{
	vars->floor->img = mlx_xpm_file_to_image(vars->mlx, "../map/FLOOR_3B.XPM", vars->floor->x, vars->floor->y);
}

void	game_loop(t_clist map)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
	mlx_hook(vars.win, 2, 1L<<0, action, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	t_clist	*map;

	if (argc != 2)
	{
		write (2, "no or to litle args", 19);
		return (0);
	}
	map = make_map(argv);
	while (map)
	{
		printf("%s %d \n", map->string, map->n_list);
		map = map->next;
	}
	return (0);
}
