/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:16:14 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/18 18:27:45 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_clist	*make_map(char **argv)
{
	int		fd;
	t_clist	*map;
	char	*string;
	t_clist	*temp;

	map = NULL;
	fd = open(argv[1], O_RDONLY);
	string = get_next_line(fd);
	while (string)
	{
		temp = c_newlist(string);
		if (!temp)
		{
			ft_printf("Error\nlist malloc problem");
			exit(0);
		}
		c_lstadd_back(&map, temp);
		string = get_next_line(fd);
	}
	close(fd);
	return (map);
}

static void	char_sprite(t_vars *vars, t_clist *map, int *xy, int space)
{
	while (map->n_list < xy[1])
		map = map->next;
	if ((map->string)[xy[0]] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall->img, xy[0] * space, xy[1] * space);
	if ((map->string)[xy[0]] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->play->img, 10 + (xy[0] * space), 10 + (xy[1] * space));
		vars->play->x = xy[0];
		vars->play->y = xy[1];
	}
	if ((map->string)[xy[0]] == 'E')
	{
		vars->exit->x = xy[0];
		vars->exit->y = xy[1];
	}
	if ((map->string)[xy[0]] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->collect->img, xy[0] * space, xy[1] * space);
		vars->play->sluge++;
	}
}

void	put_map(t_vars *vars, int space)
{
	int	xy[2];

	vars->play->sluge = 0;
	xy[0] = 0;
	xy[1] = 0;
	while (xy[1] < vars->map_y)
	{
		while (xy[0] < vars->map_x)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->floor->img, xy[0] * space, xy[1] * space);
			char_sprite(vars, vars->map, xy, space);
			xy[0]++;
		}
		xy[0] = 0;
		xy[1]++;
	}
	if (!vars->play->sluge)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit->img2,
			10 + vars->exit->x * 64, 10 + vars->exit->y * 64);
	}
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit->img,
			10 + vars->exit->x * 64, 10 + vars->exit->y * 64);
}
