/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jordan <jordan@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 16:33:13 by jordan        #+#    #+#                 */
/*   Updated: 2021/03/25 12:53:51 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	int	i;

	if (c >= 32 && c <= 126)
		i = 12;
	else
		i = 0;
	return (i);
}
