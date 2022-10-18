/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_extra.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:40:36 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/18 17:50:42 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_pro(t_vars *vars)
{
	ft_printf("%s", vars->string);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (1);
}

void	map_exit(void)
{
	perror("Error\nmap not corect");
	exit(0);
}
