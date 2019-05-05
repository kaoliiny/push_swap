/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcional.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/04/16 21:51:14 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		manage_error(int errno)
{
	const char *err_mes[42] = {"",
		"1. Oh no! Your stack is empty",
		"2. Seems like your stack consist not only the numbers",
		"3. Unfortunately your stack doesn't have a good numbers",
		"4. Sorry, you gave us not only the int numbers",
		"5. Ufff. Bad operations were found"
	};

	ft_putendl_fd(err_mes[errno], 2);
	exit(errno);
}

bool		print_op(char op[5])
{
	static char *prev_op;

	if ((!prev_op || !ft_strcmp(prev_op, "rr\n") || !ft_strcmp(prev_op, "rrr\n")
	|| !ft_strcmp(prev_op, "ss\n") || *prev_op == '\0'))
	{
		prev_op = op;
		return (true);
	}
	else if ((!ft_strcmp(prev_op, "sa\n") && !ft_strcmp(op, "sb\n"))
	|| (!ft_strcmp(prev_op, "sb\n") && !ft_strcmp(op, "sa\n")))
		write(1, "ss\n", 3) && (prev_op = "ss\n");
	else if ((!ft_strcmp(prev_op, "pb\n") && !ft_strcmp(op, "pa\n"))
	|| (!ft_strcmp(prev_op, "pa\n") && !ft_strcmp(op, "pb\n")))
		(prev_op = "\0");
	else if ((!ft_strcmp(prev_op, "ra\n") && !ft_strcmp(op, "rb\n"))
	|| (!ft_strcmp(prev_op, "rb\n") && !ft_strcmp(op, "ra\n")))
		write(1, "rr\n", 3) && (prev_op = "rr\n");
	else if ((!ft_strcmp(prev_op, "rra\n") && !ft_strcmp(op, "rrb\n"))
	|| (!ft_strcmp(prev_op, "rrb\n") && !ft_strcmp(op, "rra\n")))
		write(1, "rrr\n", 4) && (prev_op = "rrr\n");
	else if (!ft_strcmp(prev_op, "rra\n") || !ft_strcmp(prev_op, "rrb\n"))
		write(1, prev_op, 4) && (prev_op = op);
	else
		write(1, prev_op, 3) && (prev_op = op);
	return (true);
}

void		stack_create(t_stack **a, int integer, t_main *st)
{
	t_stack	*tmp;

	if (*a == NULL)
	{
		*a = ft_newlst(integer);
		st->min = integer;
		st->max = integer;
		return ;
	}
	tmp = *a;
	while (tmp)
	{
		(st->max < integer) && (st->max = integer);
		(st->min > integer) && (st->min = integer);
		if (tmp->digit == integer)
			manage_error(3);
		else if (tmp->next == NULL)
		{
			tmp->next = ft_newlst(integer);
			return ;
		}
		tmp = tmp->next;
	}
}

int			if_max(t_stack *stack, int digit)
{
	t_stack *tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (tmp->digit > digit && tmp->next != NULL)
			return (1);
		if (tmp->digit > digit)
			return (2);
	}
	return (0);
}

ssize_t		ft_atoi_spec(const char *str)
{
	int					i;
	unsigned long int	sum;
	int					minus;

	i = 0;
	sum = 0;
	minus = 1;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i++] - '0';
		if (sum > INT32_MAX && minus == 1)
			manage_error(4);
		if (sum > (unsigned long int)INT32_MAX + 1 && minus == -1)
			manage_error(4);
	}
	return (sum * minus);
}
