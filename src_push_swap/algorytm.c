/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorytm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/02/11 21:00:34 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		shake_b(int point, int count, t_main *st)
{
	int	num;
	t_stack	*tmp;
	int	new_point;

	num = 0;
	tmp = st->b;
	new_point = 0;
	while (count--)
	{
		if (!tmp)
			return (0);
		(tmp->digit >= point) ? push_stack(&st->a, &st->b) && write(1, "pa\n", 3) : rotate_a(&st->b)
		&& write(1, "rb\n", 3) && ++num && (new_point += tmp->digit);
		if (st->a->digit > st->a->next->digit)
		{
			swap_first_el(st->a);
			write(1, "sa\n", 3);
		}
		tmp = tmp->next;
	}
	(num > 2) && (st->count = num);
	(st->b) && (st->size_b = num);
	(num) && (new_point /= num);
	return (new_point);
}

void		bit2(int point, t_main *st)
{
	int	size = 0;
	int p;
	t_stack	*tmp;

	tmp = st->a;
	while (++size && tmp->digit <= point)
	{
		push_stack(&st->b, &st->a) && write(1, "pb\n", 3);
		tmp = tmp->next;
	}
	point /= 2;
	point += point / 2;
	p = point;
	while (st->b && st->size_b)
		point = shake_b(point, size, st);
	while (st->a->digit > last_a(st->a) && st->a->digit <= p)
	{
		if (st->a->digit > st->a->next->digit)
		{
			swap_first_el(st->a);
			write(1, "sa\n", 3);
		}
		rotate_a(&st->a) && write(1, "ra\n", 3);
	}
}

void		bit(int point, t_main *st)
{
	int flag;
	int	size = 0;
	t_stack	*tmp;

	flag = 0;
	tmp = st->a;
	while (++size && tmp->digit <= point)
	{
		if (tmp->digit > st->first_p && (flag = 1))
			break ;
		push_stack(&st->b, &st->a) && write(1, "pb\n", 3);
		tmp = tmp->next;
	}
	point /= 2;
	while (st->b && st->size_b)
		point = shake_b(point, size, st);
	while (st->a->digit > last_a(st->a) && st->a->digit <= st->point)
	{
		if (st->a->digit > st->a->next->digit)
		{
			swap_first_el(st->a);
			write(1, "sa\n", 3);
		}
		rotate_a(&st->a) && write(1, "ra\n", 3);
	}
	if (flag == 1)
		return ;
	if (st->a->digit > st->first_p && (point = st->max)
	&& (st->point = st->max + 1))
	{
		write(1, "\n\n\n", 3);
		second_part_bit(point, st, true);
	}
	bit2(st->point *= 2, st);
	bit(st->point, st);
}

void		bit_of_magic(int point, t_main *st, bool x)
{
	int b;
	int	size;
	int new_point_a;
	t_stack	*tmp;

	tmp = st->a;
	b = 0;
	size = 0;
	new_point_a = 0;
	while (size++ < st->count)
	{
		(tmp->digit >= point) ? rotate_a(&st->a) && write(1, "ra\n", 3) && (new_point_a += tmp->digit)
		&& (st->last_a = tmp) : push_stack(&st->b, &st->a) && write(1, "pb\n", 3)  && b++;
		tmp = tmp->next;
	}
	st->size_b = b;
	point /= 2;
	st->point = point;
	st->count -= b;
	while(st->b && st->size_b)
		point = shake_b(point, st->size_b, st);
	 while ((st->size_b--) > 0)
	 	rotate_a(&st->a) && write(1, "ra\n", 3);
	 if (st->count > 0)
	 	bit(st->point, st);
}
