/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:16:14 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/11 18:13:38 by jbax          ########   odam.nl         */
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
			write(2, "temp\n", 5);
			exit(0);
		}
		c_lstadd_back(&map, temp);
		string = get_next_line(fd);
	}
	close(fd);
	return (map);
}
	// system("leaks -q so_long");
