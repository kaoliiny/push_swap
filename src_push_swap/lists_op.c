/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/01 18:06:20 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*last_a(t_stack *stack)
{
	t_stack *tmp;

	if (!stack)
		return (false);
	tmp = stack;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

inline t_stack	*ft_newlst(int integer)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	else
	{
		new->digit = integer;
		new->next = NULL;
	}
	return (new);
}

void			stack_create(t_stack **a, int integer, t_main *st)
{
	t_stack	*tmp;

	if (*a == NULL)
	{
		*a = ft_newlst(integer);
		st->min = integer;
		st->max = integer;
		return ;
	}
	tmp = *a;
	while (tmp != NULL)
	{
		(st->max < integer) && (st->max = integer);
		(st->min > integer) && (st->min = integer);
		if (tmp->digit == integer)
			manage_error(3);
		else if (tmp->next == NULL)
		{
			tmp->next = ft_newlst(integer);
			return ;
		}
		tmp = tmp->next;
	}
}
