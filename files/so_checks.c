/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_checks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 14:36:35 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/19 17:52:43 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_valid_char(t_clist *map, int i, t_map *cep, t_vars *vars)
{
	if (map->string[i] == '1')
		return (1);
	if (map->string[i] == '0')
		return (2);
	if (map->string[i] == 'P' || map->string[i] == 'E' || map->string[i] == 'C')
	{
		if (map->string[i] == 'P')
		{
			cep->map_p++;
			vars->play->x = i;
			vars->play->y = map->n_list;
		}
		if (map->string[i] == 'E')
			cep->map_e++;
		if (map->string[i] == 'C')
		{
			cep->map_c++;
			vars->exit->sluge = cep->map_c;
		}
		return (2);
	}
	return (0);
}

static int	test_wall(t_clist *map, int i, t_map *cep, t_vars *vars)
{
	if (!i && !map->n_list)
	{
		cep->map_c = 0;
		cep->map_p = 0;
		cep->map_e = 0;
	}
	if (!check_valid_char(map, i, cep, vars))
		map_exit("Error\ninvalid chars in map\n");
	if (!map->back || !map->next)
	{
		if (map->string[i] != '1')
			map_exit("Error\nmap is not corectly walled\n");
	}
	if (i == 0 || map->string[i + 1] == '\n')
	{
		if (map->string[i] != '1')
			map_exit("Error\nmap is not corectly walled\n");
	}
	return (1);
}

static int	walk_route(char **route, int x, int y, t_map *cep)
{
	if (route[y][x] == 'E')
		return (0);
	if (route[y][x] == 'C')
		cep->map_p += 1;
	route[y][x] = '1';
	if (route[y - 1][x] != '1')
		cep->map_e = walk_route(route, x, y - 1, cep);
	if (route[y][x - 1] != '1')
		cep->map_e = walk_route(route, x - 1, y, cep);
	if (route[y][x + 1] != '1')
		cep->map_e = walk_route(route, x + 1, y, cep);
	if (route[y + 1][x] != '1')
		cep->map_e = walk_route(route, x, y + 1, cep);
	return (cep->map_e);
}

static void	map_route(t_clist *map, t_vars *vars, t_map *cep)
{
	char	**test_route;

	test_route = malloc(vars->map_y * sizeof(char *));
	if (!test_route)
		map_exit("Error\nmalloc failed\n");
	cep->map_e = 0;
	cep->map_p = 0;
	while (map)
	{
		test_route[cep->map_e] = ft_strdup(map->string);
		if (!test_route[cep->map_e])
			map_exit("Error\nmalloc failed\n");
		cep->map_e += 1;
		map = map->next;
	}
	if (walk_route(test_route, vars->play->x, vars->play->y, cep))
		map_exit("Error\ncan't exit the map\n");
	if (cep->map_p != cep->map_c)
		map_exit("Error\ncan't collect all the sluge\n");
	while (cep->map_p - cep->map_c < vars->map_y)
	{
		free(test_route[cep->map_p - cep->map_c]);
		cep->map_p += 1;
	}
	free(test_route);
}

void	check_map(t_clist *map, t_vars *vars)
{
	int		i;
	t_map	cep;

	i = 0;
	vars->map_x = 0;
	while (map->next)
	{
		while (map->string[i] != '\n')
			i += test_wall(map, i, &cep, vars);
		if (!vars->map_x)
			vars->map_x = i;
		if (i != vars->map_x || !i)
			map_exit("Error\nmap is not rectangular\n");
		i = 0;
		map = map->next;
	}
	while (map->string[i] && map->string[i] != '\n')
		i += test_wall(map, i, &cep, vars);
	find_error(&cep, i, vars->map_x);
	vars->map_y = map->n_list + 1;
	while (map->back)
		map = map->back;
	map_route(map, vars, &cep);
}
