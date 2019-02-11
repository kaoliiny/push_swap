/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcional.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/02/11 23:48:11 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_sort(t_stack *stack, int point, t_main *st)
{
	int	min;
	t_stack *tmp;

	min = 0;
	if (!stack || stack->digit > point)
	return (0);
	tmp = stack;
	while (tmp && tmp->digit != st->min)
	{
		if (tmp->digit > point)
			break ;
		if (stack->digit > tmp->digit && tmp->digit != stack->next->digit)
			return(0);
		tmp = tmp->next;
	}
	return (1);
}

int				is_r_sort(t_stack *stack, int point, t_main *st)
{
	int	min;
	t_stack *tmp;

	min = 0;
	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->digit > point)
			break ;
		if (tmp->digit < tmp->next->digit)
			return(0);
		tmp = tmp->next;
	}
	return (1);
}

int				last_a(t_stack *stack)
{
	t_stack *tmp;

	if (!stack)
	return (false);
	tmp = stack;
	while (tmp)
	{
		if (tmp->next == NULL)
		return (tmp->digit);
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
