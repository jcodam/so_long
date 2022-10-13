/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:04:13 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/13 18:23:16 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aloc_vars(t_vars *vars, t_clist *map)
{
	vars->play = malloc(sizeof(t_player));
	vars->floor = malloc(sizeof(t_data));
	vars->wall = malloc(sizeof(t_data));
	vars->exit = malloc(sizeof(t_player));
	vars->collect = malloc(sizeof(t_data));
	vars->map = map;
	vars->exit->img = mlx_xpm_file_to_image(vars->mlx, "image/BARREL_1.xpm", &vars->play->x, &vars->play->y);
	vars->exit->img2 = mlx_xpm_file_to_image(vars->mlx, "image/BARREL_3.xpm", &vars->play->x, &vars->play->y);
	vars->play->img = mlx_xpm_file_to_image(vars->mlx, "image/Ghost1.xpm", &vars->play->x, &vars->play->y);
	vars->floor->img = mlx_xpm_file_to_image(vars->mlx, "image/FLOOR_3B.xpm", &vars->floor->x, &vars->floor->y);
	vars->wall->img = mlx_xpm_file_to_image(vars->mlx, "image/PIPES_2A.xpm", &vars->wall->x, &vars->wall->y);
	vars->collect->img = mlx_xpm_file_to_image(vars->mlx, "image/SLIME_1A.xpm", &vars->wall->x, &vars->wall->y);
}

void	move(t_vars *vars, t_clist *map, int x, int y)
{
	char c;
	t_clist *temp;

	temp = map;
	while (y > map->n_list)
		map = map->next;
	while (vars->play->y > temp->n_list)
		temp = temp->next;
	if (map->string[x] != '1')
	{
		
		c = map->string[x];
		if (map->string[x] == 'C')
		{
			c = '0';
			
		}
		map->string[x] = temp->string[vars->play->x];
		temp->string[vars->play->x] = c;
	}
}

int		action(int key, t_vars *vars)
{
	printf("%d\n", key);
	if (key == 13)
		move(vars, vars->map, vars->play->x, vars->play->y - 1);
	if (key == 1)
		move(vars, vars->map, vars->play->x, vars->play->y + 1);
	if (key == 0)
		move(vars, vars->map, vars->play->x - 1, vars->play->y);
	if (key == 2)
		move(vars, vars->map, vars->play->x + 1, vars->play->y);
	if (key == 35)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->play->img, 0, 60);
	if (key == 31)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floor->img, 0, 60);
	if (key == 34)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall->img, 0, 60);
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	put_map(vars, 64);
	return (0);
}

void	game_loop(t_clist *map)
{
	t_vars	vars;

	if (!map)
		write(2,"test\n",5);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1024, 384, "so_long");
	aloc_vars(&vars, map);

	put_map(&vars, 64);
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
	// while (map)
	// {
	// 	printf("%s %d \n", map->string, map->n_list);
	// 	map = map->next;
	// }
	game_loop(map);
	return (0);
}
