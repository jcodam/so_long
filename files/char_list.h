/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_list.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:43:43 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/11 17:52:04 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_LIST_H
# define CHAR_LIST_H

# include <stdlib.h>

typedef struct s_clist {
	char			*string;
	int				n_list;
	struct s_clist	*next;
	struct s_clist	*back;
}				t_clist;

t_clist	*c_newlist(char *string);
void	c_lstadd_back(t_clist **list, t_clist *new);

#endif