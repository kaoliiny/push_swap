/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/06 20:52:46 by kaoliiny         ###   ########.fr       */
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

bool			is_sorted_stack_a(t_stack *stack)
{
	int		min;
	t_stack *tmp;

	min = 0;
	if (!stack)
		return (1);
	tmp = stack;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->digit > tmp->next->digit)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
