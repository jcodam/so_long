/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_extra.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:40:36 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/19 17:52:58 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_pro(t_vars *vars)
{
	ft_putstr_fd(vars->string, 1);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (1);
}

void	map_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

void	find_error(t_map *cep, int i, int x)
{
	if (cep->map_c < 1)
		map_exit("Error\nno sluge to collect in map\n");
	if (cep->map_e < 1)
		map_exit("Error\nno exit in map\n");
	if (cep->map_e > 1)
		map_exit("Error\nmore than 1 exit in map\n");
	if (cep->map_p < 1)
		map_exit("Error\nno player in map\n");
	if (cep->map_p > 1)
		map_exit("Error\nmore than 1 player in map\n");
	if (i != x)
		map_exit("Error\nmap is not rectangular\n");
}

void	_ber(char *arg)
{
	int		i;
	char	*str;

	i = 0;
	str = ".ber";
	while (arg[i] != '.' && arg[i])
		i++;
	while (arg[i] == *str && arg[i] && *str)
	{
		str++;
		i++;
	}
	if (arg[i] || *str)
		map_exit("Error\nno .ber file\n");
}
