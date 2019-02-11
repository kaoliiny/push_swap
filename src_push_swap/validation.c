/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/02/11 21:34:26 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_num(const char *str)
{
	while(*str)
		if (!ft_isdigit((int)*str++))
			manage_error(2);
	return(true);
}

void validation(t_main *st, int argc, char **argv)
{
	int sum;
	int	num;

	sum = 0;
	num = 0;
	st->a = NULL;
	st->b = NULL;
	while (--argc && is_num(argv[argc]) && (sum += num) | 1)
		stack_create(&st->a, num = ft_atoi(argv[argc]), st); // x < INT32_MIN || x > INT32_MAX
 //   push_stack(&b, &a);
//	swap_first_el(a);
//	a = rev_rotate(&a);
//	b = rev_rotate(&b);
	st->first_p = sum / st->count;
	bit_of_magic(st->first_p, st, false);
}