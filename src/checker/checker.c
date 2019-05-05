/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:07:33 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/04/16 21:47:58 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool		is_numer(const char *str)
{
	if (!str)
		return (false);
	while (*str)
		if (!ft_isdigit((int)*str) && *str != '-')
		{
			write(1, "error\n", 6);
			exit(-1);
		}
		else
			str++;
	return (true);
}

static void		check_valid(t_main *st, int argc, char **argv)
{
	int	i;
	int sum;
	int	num;

	i = 0;
	sum = 0;
	num = 0;
	st->a = NULL;
	st->b = NULL;
	st->ib = 0;
	st->il = 0;
	if (argc == 2)
	{
		argv = ft_strsplit(argv[1], ' ');
		while (argv[i] && is_numer(argv[i]) && (sum += num) | 1)
			stack_create(&st->a, num = ft_atoi_spec(argv[i++]), st);
		free_array(&argv);
	}
	else
		while (i++ < argc - 1 && is_numer(argv[i]) && (sum += num) | 1)
			stack_create(&st->a, num = ft_atoi_spec(argv[i]), st);
	if (is_sorted_stack_a(st->a))
		return ;
}

static void		manage_op(t_main *st, char *op)
{
	if (!ft_strcmp(op, "sa"))
		swap_first_el(st->a);
	else if (!ft_strcmp(op, "sb"))
		swap_first_el(st->b);
	else if (!ft_strcmp(op, "ss"))
		swap_first_el(st->b) && swap_first_el(st->a);
	else if (!ft_strcmp(op, "pa"))
		push_stack(&st->a, &st->b);
	else if (!ft_strcmp(op, "pb"))
		push_stack(&st->b, &st->a);
	else if (!ft_strcmp(op, "ra"))
		rotate_a(&st->a);
	else if (!ft_strcmp(op, "rb"))
		rotate_a(&st->b);
	else if (!ft_strcmp(op, "rr"))
		rotate_a(&st->a) && rotate_a(&st->b);
	else if (!ft_strcmp(op, "rra"))
		st->a = rev_rotate(&st->a, st);
	else if (!ft_strcmp(op, "rrb"))
		(st->b) && (st->b = rev_rotate(&st->b, st));
	else if (!ft_strcmp(op, "rrr"))
		(st->a = rev_rotate(&st->a, st))
		&& (st->b) && (st->b = rev_rotate(&st->b, st));
	else
		manage_error(5);
}

int				main(int argc, char **argv)
{
	t_main	check;
	int		byte;
	char	*op;

	byte = 0;
	if (argc <= 1)
		manage_error(1);
	check_valid(&check, argc, argv);
	while ((byte = get_next_line((const int)0, &op)) > 0)
	{
		manage_op(&check, op);
		if (byte > 4 || byte == -1 || !argv[1])
		{
			write(1, "eror\n", 5);
			return (0);
		}
		free(op);
	}
	(is_sorted_stack_a(check.a)) ?
	write(1, "\033[0;92mOK\n", 10) : write(1, "\033[0;91mKO\n", 10);
	return (0);
}
