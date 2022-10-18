/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:04:13 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/18 18:28:23 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	aloc_vars2(t_vars *vars)
{
	vars->exit->img = mlx_xpm_file_to_image(vars->mlx,
			"image/BARREL_1.xpm", &vars->play->x, &vars->play->y);
	vars->exit->img2 = mlx_xpm_file_to_image(vars->mlx,
			"image/BARREL_3.xpm", &vars->play->x, &vars->play->y);
	vars->play->img_r = mlx_xpm_file_to_image(vars->mlx,
			"image/Ghost1.xpm", &vars->play->x, &vars->play->y);
	vars->play->img2 = mlx_xpm_file_to_image(vars->mlx,
			"image/Ghost2.xpm", &vars->play->x, &vars->play->y);
	vars->play->img3 = mlx_xpm_file_to_image(vars->mlx,
			"image/GhostB.xpm", &vars->play->x, &vars->play->y);
	vars->play->img_l = mlx_xpm_file_to_image(vars->mlx,
			"image/Ghost3.xpm", &vars->play->x, &vars->play->y);
	vars->floor->img = mlx_xpm_file_to_image(vars->mlx,
			"image/FLOOR_3B.xpm", &vars->floor->x, &vars->floor->y);
	vars->wall->img = mlx_xpm_file_to_image(vars->mlx,
			"image/PIPES_2A.xpm", &vars->wall->x, &vars->wall->y);
	vars->collect->img = mlx_xpm_file_to_image(vars->mlx,
			"image/SLIME_1A.xpm", &vars->wall->x, &vars->wall->y);
}

static void	aloc_vars(t_vars *vars, t_clist *map)
{
	vars->play = malloc(sizeof(t_player));
	vars->floor = malloc(sizeof(t_data));
	vars->wall = malloc(sizeof(t_data));
	vars->exit = malloc(sizeof(t_player));
	vars->collect = malloc(sizeof(t_data));
	vars->string = "Error\nmalloc problem\n";
	if (!vars->play || !vars->floor || !vars->exit)
		exit_pro(vars);
	if (!vars->collect || !vars->wall)
		exit_pro(vars);
	vars->play->steps = 0;
	vars->map = map;
	aloc_vars2(vars);
	vars->play->img = vars->play->img2;
}

static void	move(t_vars *vars, t_clist *map, int x, int y)
{
	char	c;
	t_clist	*temp;

	temp = map;
	while (y > map->n_list)
		map = map->next;
	while (vars->play->y > temp->n_list)
		temp = temp->next;
	if (map->string[x] != '1' && map->string[x] != 'E')
	{
		vars->play->steps++;
		ft_printf("%d\n", vars->play->steps);
		c = map->string[x];
		if (map->string[x] == 'C')
		{
			vars->exit->sluge -= 1;
			c = '0';
		}
		map->string[x] = temp->string[vars->play->x];
		temp->string[vars->play->x] = c;
	}
	if (map->string[x] == 'E' && !vars->exit->sluge)
		exit_pro(vars);
}

static int	action(int key, t_vars *vars)
{
	char	*steps;

	if (key == 13)
		vars->play->img = vars->play->img3;
	if (key == 13)
		move(vars, vars->map, vars->play->x, vars->play->y - 1);
	if (key == 1)
		vars->play->img = vars->play->img2;
	if (key == 1)
		move(vars, vars->map, vars->play->x, vars->play->y + 1);
	if (key == 0)
		vars->play->img = vars->play->img_l;
	if (key == 0)
		move(vars, vars->map, vars->play->x - 1, vars->play->y);
	if (key == 2)
		vars->play->img = vars->play->img_r;
	if (key == 2)
		move(vars, vars->map, vars->play->x + 1, vars->play->y);
	if (key == 53)
		exit_pro(vars);
	put_map(vars, 64);
	steps = ft_itoa(vars->play->steps);
	mlx_string_put(vars->mlx, vars->win, 10, 20, 0x00FFFFFF, steps);
	free(steps);
	return (0);
}

// void	ffclose(void)
// {
// 	system("leaks -q so_long");
// }
	// atexit(ffclose);

int	main(int argc, char **argv)
{
	t_clist	*map;
	t_vars	vars;

	if (argc != 2)
	{
		write (2, "no or to litle args", 19);
		return (0);
	}
	map = make_map(argv);
	vars.mlx = mlx_init();
	aloc_vars(&vars, map);
	vars.string = "";
	check_map(map, &vars);
	vars.win = mlx_new_window(vars.mlx, vars.map_x * 64,
			vars.map_y * 64, "so_long");
	put_map(&vars, 64);
	mlx_hook(vars.win, 2, 1L << 0, action, &vars);
	mlx_hook(vars.win, 17, 0L, exit_pro, &vars);
	mlx_loop(vars.mlx);
	exit(0);
}
