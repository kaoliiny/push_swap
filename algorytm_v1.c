/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorytm_v1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/02/03 19:49:55 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	shake_b(int point, int count, t_main *st)
// {
// 	int	num;
// 	t_stack	*tmp;
// 	int	new_point;

// 	num = 0;
// 	tmp = st->b;
// 	new_point = 0;
// 	//is_sorted();
// 	while (count--)
// 	{
// 		(tmp->digit >= point) ? push_stack(&st->a, &st->b) && write(1, "pa\n", 3) : rotate_a(&st->b)
// 		&& write(1, "rb\n", 3) && ++num && (new_point += tmp->digit);
// 		tmp = tmp->next;
// 	}
// 	(st->b) && (st->size_b = num);
// 	(num) && (new_point /= num);
// 	return (new_point);
// }

// void		bit_of_magic(int point, t_main *st, bool x)
// {
// 	int i;
// 	int b;
// 	int	size;
// 	int new_point_a;
// 	t_stack	*tmp;
// 	//t_stack	*last_a;
// 	//t_stack	*last_b;

// 	tmp = st->a;
// 	b = 0;
// 	i = 0;
// 	size = 0;
// 	new_point_a = 0;
// 	while (size++ < st->count)
// 	{
// 		(tmp->digit > point) ? rotate_a(&st->a) && write(1, "ra\n", 3) && (new_point_a += tmp->digit) && (st->last_a = tmp)
// 		: push_stack(&st->b, &st->a) && write(1, "pb\n", 3)  && b++;
// 		tmp = tmp->next;
// 	}
// 	st->size_b = b;
// 	st->point = point;
// 	point /= 2;
// 	while (x && new_point_a && st->last_a->digit > st->point)
// 	 	st->a = rev_rotate(&st->a, st) && write(1, "rra\n", 3);
// 	st->count -= b;
// 	while(st->b && st->size_b)
// 		point = shake_b(point, st->size_b, st);
// 	while ((b-- - i) > 0)
// 	{
// 		(st->a->digit > st->a->next->next->digit && st->a->next->next->digit != st->min && st->a->next->digit != st->min)
// 				&& push_stack(&st->b, &st->a) && i++;
// 		if (st->a->digit > st->a->next->digit && st->a->next->digit != st->min)
// 			{
// 				(st->a->digit > st->a->next->next->digit && st->a->next->next->digit != st->min)
// 				&& push_stack(&st->b, &st->a) && i++;
// 				swap_first_el(st->a);
// 				write(1, "sa\n", 3);
// 			}
// 		rotate_a(&st->a) && write(1, "ra\n", 3);
// 	}
// 	while (i--)
// 		{
// 			push_stack(&st->a, &st->b) && write(1, "pa\n", 3) ;
// 			rotate_a(&st->a) && write(1, "ra\n", 3);
// 		}
// 	if (st->count && count < 40)
// 		bit_of_magic(new_point_a / st->count, st, true);
	// if (count > 40)
	// 	bit_of_magic((new_point_a / st->count) / 2, st, true);
}
