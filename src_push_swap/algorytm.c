/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorytm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/04 00:48:23 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		shake_b(int point, int count, t_main *st)
{
	bool		i;
	int			digit;
	t_stack		*tmp;
	int			new_point;

	i = false;
	tmp = st->a;
	new_point = 0;
	while (count--)
	{
		if (!tmp)
			return ;
		(i == 0 && tmp->digit > point) && (i = 1) && (digit = st->a->digit);
		(tmp->digit <= point) ?
		push_stack(&st->b, &st->a) && print_op("pb\n")
		: rotate_a(&st->a) && print_op("ra\n")
		&& (new_point += tmp->digit);
		if (tmp->next != NULL && tmp->next->digit != digit)
			tmp = tmp->next;
		else
			break ;
	}
}

void	main_alg(t_main *st)
{
	while (st->b && st->b->digit >= st->first_p)
	{
	 	if (is_sort(st->b, st))
	 	{
			if (st->b->next->digit && st->b->digit < st->b->next->digit)
				swap_first_el(st->b) && write(1, "sb\n", 3);
			while (if_max(st->last_b, st->b->digit, st))
			{
				st->a = rev_rotate(&st->a, st);
				write(1, "rra\n", 4);
			}
			(st->b->digit < st->a->digit) &&
			push_stack(&st->a, &st->b) && write(1, "pa\n", 3);
		}
		if (st->b->digit > st->a->digit && if_max(st->last_b, st->a->digit, st))
			while (st->b->digit > st->a->digit && if_max(st->last_b, st->a->digit, st))
			{
				st->a = rev_rotate(&st->a, st);
				write(1, "rra\n", 4);
			}
		else if (st->b->digit < st->a->digit)
		{
			while (st->b->digit < st->a->digit && if_max(st->last_b, st->b->digit, st))
			{
				st->a = rev_rotate(&st->a, st);
				write(1, "rra\n", 4);
			}
			(st->b && st->b->digit >= st->first_p) && 
			push_stack(&st->a, &st->b) && write(1, "pa\n", 3);
		}
		else
			while (st->b->digit > st->a->digit)
				 rotate_a(&st->a) && write(1, "ra\n", 3);
	}
}

void		bit(t_main *st)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = st->a;
	while (i <= st->ib && st->a->next != NULL)
	{
		shake_b(st->big_pivots[i], st->count, st);
		if (st->a == NULL || st->a->next == NULL || st->a->next->next == NULL)
			break ;
		i++;
	}
	if (--i && st->a->next && st->a->digit >= st->a->next->digit)
		swap_first_el(st->a) && print_op("sa\n");
	print_op("\0");
	if (is_sorted_stack_a(st->a, st) && st->b == NULL)
		return ;
	(st->a->next) ? (st->last_b = st->a->next) : (st->last_b = st->a);
	main_alg(st);
	while (st->last_b->next)
	{
		st->a = rev_rotate(&st->a, st);
		write(1, "rra\n", 4);
	}
	one_more_bit(st);
}

void		bit_of_magic(int point, t_main *st)
{
	int		size;
	int		new_point_a;
	t_stack	*tmp;

	tmp = st->a;
	size = 0;
	new_point_a = 0;
	while (size++ < st->count)
	{
		if (tmp && tmp->digit >= point)
			rotate_a(&st->a) && print_op("ra\n") &&
			(new_point_a += tmp->digit) && (st->last_a = tmp);
		else
			push_stack(&st->b, &st->a) && print_op("pb\n") &&
			(st->b->digit < st->little_pivots[1])
			&& (st->b->next) && rotate_a(&st->b) && print_op("rb\n");
		tmp = tmp->next;
	}
	if (st->count > 0)
	 	bit(st);
}
