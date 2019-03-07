/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_second_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/06 19:56:48 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			if_min(t_stack *stack, int digit, t_main *st)
{
	t_stack *tmp;

	if (!stack || stack->digit == st->first_p)
		return (0);
	tmp = stack;
	while (tmp && tmp->next && tmp->digit < st->first_p)
	{
		if (tmp->digit >= st->first_p)
			break ;
		if (tmp->digit < digit && tmp->next != NULL)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		shakin_b(t_main *st, int i)
{
	t_stack		*tmp;

	tmp = st->a;
	while (st->b != NULL && st->b->digit >= st->little_pivots[1])
	{
		if (st->b->digit <= st->little_pivots[i])
			rotate_a(&st->b) && print_op("rb\n");
		else
		{
			while (if_min(st->a, st->b->digit, st))
				rotate_a(&st->a) && print_op("ra\n");
			while (st->b->digit < st->a->digit
				&& if_max(st->last_b, st->b->digit, st))
			{
				st->a = rev_rotate(&st->a, st);
				print_op("rra\n");
			}
			push_stack(&st->a, &st->b) && print_op("pa\n");
		}
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
}

void		shake(t_main *st, t_stack *a_last)
{
	int	i;

	i = 3;
	while (i <= st->il)
	{
		while (st->b != a_last && st->b != NULL)
			if (st->b->digit <= st->little_pivots[i])
				rotate_a(&st->b) && print_op("rb\n");
			else
			{
				while (if_min(st->a, st->b->digit, st))
					rotate_a(&st->a) && print_op("ra\n");
				while (st->b->digit < st->a->digit
					&& if_max(st->last_b, st->b->digit, st))
				{
					st->a = rev_rotate(&st->a, st);
					print_op("rra\n");
				}
				push_stack(&st->a, &st->b) && print_op("pa\n");
			}
		if (st->b->digit == a_last->digit)
			a_last = last_a(st->b);
		i++;
	}
}

void		last_shake(t_main *st)
{
	while (st->b)
	{
		while (if_min(st->a, st->b->digit, st))
			rotate_a(&st->a) && print_op("ra\n");
		while (st->b->digit < st->a->digit
			&& if_max(st->last_b, st->b->digit, st))
		{
			st->a = rev_rotate(&st->a, st);
			print_op("rra\n");
		}
		push_stack(&st->a, &st->b) && print_op("pa\n");
	}
	print_op("\0");
	while (st->last_b->next != NULL)
	{
		st->a = rev_rotate(&st->a, st);
		write(1, "rra\n", 4);
	}
}

void		one_more_bit(t_main *st)
{
	t_stack	*a_last;

	a_last = last_a(st->b);
	shakin_b(st, 0);
	while (st->last_b->next != NULL)
	{
		st->a = rev_rotate(&st->a, st);
		print_op("rra\n");
	}
	while (a_last != NULL && a_last->next != NULL && st->b != NULL)
	{
		st->b = rev_rotate(&st->b, st);
		print_op("rrb\n");
		while (if_min(st->a, st->b->digit, st))
			rotate_a(&st->a) && print_op("ra\n");
		while (st->b->digit < st->a->digit
			&& if_max(st->last_b, st->b->digit, st))
		{
			st->a = rev_rotate(&st->a, st);
			print_op("rra\n");
		}
		push_stack(&st->a, &st->b) && print_op("pa\n");
	}
	shake(st, a_last);
	last_shake(st);
}
