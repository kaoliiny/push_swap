/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorytm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/08 20:13:25 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shake_b(int point, int count, t_main *st)
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
		(i == 0 && tmp->digit > point) && (i = 1)
		&& (digit = A_DIGIT);
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

void	algo(t_main *st)
{
	if (B_DIGIT > A_DIGIT && if_max(st->last_b, A_DIGIT))
		while (B_DIGIT > A_DIGIT && if_max(st->last_b, A_DIGIT))
		{
			st->a = rev_rotate(&st->a, st);
			write(1, "rra\n", 4);
		}
	else if (B_DIGIT < A_DIGIT)
	{
		while (B_DIGIT < A_DIGIT && if_max(st->last_b, B_DIGIT))
		{
			st->a = rev_rotate(&st->a, st);
			write(1, "rra\n", 4);
		}
		(st->b && B_DIGIT >= st->first_p) &&
		push_stack(&st->a, &st->b) && write(1, "pa\n", 3);
	}
	else
		while (B_DIGIT > A_DIGIT)
			rotate_a(&st->a) && write(1, "ra\n", 3);
}

void	main_alg(t_main *st)
{
	while (st->b && B_DIGIT >= st->first_p)
	{
		if (is_sort(st->b))
		{
			if (st->b->next->digit && B_DIGIT < st->b->next->digit)
				swap_first_el(st->b) && print_op("sb\n");
			while (if_max(st->last_b, B_DIGIT))
			{
				st->a = rev_rotate(&st->a, st);
				print_op("rra\n");
			}
			(B_DIGIT < A_DIGIT) &&
			push_stack(&st->a, &st->b) && print_op("pa\n");
		}
		print_op("\0");
		algo(st);
	}
}

void	bit(t_main *st)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = st->a;
	while (i <= st->ib && st->a->next != NULL)
	{
		shake_b(st->big_pivots[i++], st->count, st);
		if (st->a == NULL || st->a->next == NULL || st->a->next->next == NULL)
			break ;
	}
	if (--i && st->a->next && A_DIGIT >= st->a->next->digit)
		swap_first_el(st->a) && print_op("sa\n");
	if (is_sorted_stack_a(st->a) && st->b == NULL)
		return ;
	(st->a->next) ? (st->last_b = st->a->next)
	: (st->last_b = st->a);
	main_alg(st);
	while (st->last_b->next)
	{
		st->a = rev_rotate(&st->a, st);
		write(1, "rra\n", 4);
	}
	one_more_bit(st);
}

void	bit_of_magic(int point, t_main *st)
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
			rotate_a(&st->a) && print_op("ra\n")
			&& (new_point_a += tmp->digit) && (st->last_a = tmp);
		else
			push_stack(&st->b, &st->a) && print_op("pb\n") \
			&& (B_DIGIT < st->little_pivots[1]) \
			&& (st->b->next) && rotate_a(&st->b) && print_op("rb\n");
		tmp = tmp->next;
	}
	if (st->count > 0)
		bit(st);
}
