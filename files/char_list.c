/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbax <jbax@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:42:23 by jbax          #+#    #+#                 */
/*   Updated: 2022/10/11 18:07:33 by jbax          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char_list.h"

t_clist	*c_newlist(char *string)
{
	t_clist	*new;

	new = malloc(sizeof(struct s_clist));
	if (!new)
		return (NULL);
	else
	{
		new->string = string;
		new->n_list = 0;
		new->next = NULL;
		new->back = NULL;
	}
	return (new);
}

void	c_lstadd_back(t_clist **list, t_clist *new)
{
	if (!(*list))
		*list = new;
	else
	{
		while ((*list)->next)
			*list = (*list)->next;
		(*list)->next = new;
		new->back = *list;
		new->n_list = (*list)->n_list + 1;
		while ((*list)->back)
			*list = (*list)->back;
	}
}
