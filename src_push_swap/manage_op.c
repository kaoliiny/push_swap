/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:06:29 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/04 00:45:02 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push_stack(t_stack **dest, t_stack **src)
{
	t_stack *tmp;
	// t_stack	*free_st;

	tmp = *dest;
	if (!src || !dest || !*src)
		return (false);
	if (!*dest)
		*dest = ft_newlst((*src)->digit);
	else
	{
		tmp = ft_newlst((*src)->digit);
		tmp->next = *dest;
		*dest = tmp;
	}
	// free_st = *src;
	*src = (*src)->next;
	// free(free_st);
	// free_st = NULL;
	return (true);
}

bool	swap_first_el(t_stack *stack)
{
	int el;

	if (!stack || !stack->next)
		return (true);
	el = stack->digit;
	stack->digit = stack->next->digit;
	stack->next->digit = el;
	return (true);
}

bool	rotate_a(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack)
		return (false);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = ft_newlst((*stack)->digit);
			break ;
		}
		tmp = tmp->next;
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	tmp = NULL;
	return (true);
}

t_stack	*rev_rotate(t_stack **stack, t_main *st)
{
	t_stack *tmp;
	t_stack *last;

	if (!stack)
		return (NULL);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->next != NULL)
			st->last_a = tmp;
		else
		{
			last = tmp;
			last->next = *stack;
			st->last_a->next = NULL;
			return (last);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
