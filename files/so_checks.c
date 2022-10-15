/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_checks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 14:36:35 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/15 16:08:46 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		dd(char c)
{
	if (c == '1')
		return (1);
	if (c == '0' || c == 'P' || c == 'C' || c == 'E')
		return (2);
	return (0);
}

int		tt(t_clist *map, int i)
{
	if (!dd(map->string[i]))
		exit(2);
	if (!map->back || !map->next)
	{
		if (map->string[i] != '1')
			exit(2);
	}
	if (i == 0 || map->string[i + 1] == '\n')
	{
		if (map->string[i] != '1')
			exit(2);
	}
	return (1);
}
void	check_map(t_clist *map, t_vars *vars)
{
	int	i;

	i = 0;
	vars->map_len = 0;
	while (map->next)
	{
		while (map->string[i] != '\n')
		{
			i += tt(map, i);
		}
		if (!vars->map_len)
			vars->map_len = i;
		if (i != vars->map_len)
			exit(2);
		i = 0;
		map = map->next;
	}
}
