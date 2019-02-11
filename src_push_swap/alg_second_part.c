/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_second_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/02/11 23:52:26 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check(int point, int count, t_main *st)
{
	float	n;
	int		b;
	int		num;
	t_stack	*tmp;
	int		new_point;

	b = 0;
	num = 0;
	tmp = st->b;
	new_point = 0;
	while (count--)
	{
		if(!tmp)
			break ;
		(tmp->digit > point) ? (new_point += tmp->digit) && b++ : ++num;
		tmp = tmp->next;
	}
	(num > 2) && (st->count = num);
	return ((num) ? 0 : (new_point / b));
}

int		rev_shake_b(int point, int count, t_main *st)
{
	int	num;
	t_stack	*tmp;
	int	new_point;
	int chick = 0;

	num = 0;
	tmp = st->b;
	new_point = 0;
	if ((chick = check(point, count, st)))
		point = chick;
	while (count--)
	{
		if(!tmp)
			return (0);
		(tmp->digit >= point) ? push_stack(&st->a, &st->b) && write(1, "pa\n", 3) : rotate_a(&st->b)
		&& write(1, "rb\n", 3) && ++num && (new_point += tmp->digit);
		tmp = tmp->next;
	}
	st->last_b = tmp;
	(st->count = num);
	(st->b) && (st->size_b = num);
	(num) && (new_point /= num);
	return (new_point);
}

void	second_part_bit(int point, t_main *st, bool x)
{
	static int		i;
	static int		pivots[25];
	int				size = 0;
	t_stack			*tmp;

	tmp = st->a;
	while (++size && tmp->digit > st->min && tmp->digit <= point)
		push_stack(&st->b, &st->a) && write(1, "pb\n", 3) && (tmp = tmp->next);
	(x) && (pivots[i] = point);
	(st->b == NULL)
	&& (st->point = point * 1.5);
	while (st->b)
	{
		if (is_r_sort(st->b, pivots[i], st))
			while(st->b)
				push_stack(&st->a, &st->b) && write(1, "pa\n", 3);
		else
		{
			point = rev_shake_b(point, size, st);
			(point && x) && ++i && (pivots[i] = point);
		}
	}
	while (st->a->digit != st->min)
	{
		if (is_sort(st->a, pivots[i], st))
		{
			if (st->a->digit > st->a->next->digit && st->a->next->digit != st->min)
			{
				swap_first_el(st->a);
				write(1, "sa\n", 3);
			}
			if (st->b)
				if (st->a->digit > st->b->digit)
					push_stack(&st->a, &st->b) && write(1, "pa\n", 3);
			rotate_a(&st->a) && write(1, "ra\n", 3);
		}
		else if (st->a->digit < pivots[i])
				push_stack(&st->b, &st->a) && write(1, "pb\n", 3);
		else
		{
			(st->b) && push_stack(&st->a, &st->b) && write(1, "pa\n", 3);
			break ;
		}
	}
	if (st->a->digit == st->min)
		exit(0);
	second_part_bit(pivots[--i], st, false);
}
