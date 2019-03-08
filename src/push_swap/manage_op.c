/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:06:29 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/08 22:33:48 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push_stack(t_stack **dest, t_stack **src)
{
	t_stack		*tmp;

	if (!dest || !src || !*src)
		return (false);
	if (!*dest)
		*dest = ft_newlst((*src)->digit);
	else
	{
		tmp = ft_newlst((*src)->digit);
		tmp->next = *dest;
		*dest = tmp;
	}
	tmp = *src;
	*src = (*src)->next;
	free(tmp);
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
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_newlst((*stack)->digit);
	// tmp = *stack;
	*stack = (*stack)->next;
	// free(tmp);
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
