/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/03 21:23:00 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	bool is_num(const char *str)
{
	if (!str)
		return (false);
	while (*str)
		if (!ft_isdigit((int)*str) && *str != '-')
			manage_error(2);
		else
			str++;
	return (true);
}

static void	pivots_searching(int *tab, t_main *st)
{
	int		i;
	int		a;
	float	k;

	i = 4;
	k = 0.0;
	a = st->count / 2;
	(st->count > 600) && (LITTLE_PIVOTS = tab[a - st->count / 40]) && st->il++;
	(st->count > 350) && (LITTLE_PIVOTS = tab[a - st->count / 20]) && st->il++;
	(st->count > 200) && (LITTLE_PIVOTS = tab[a - st->count / 10]) && st->il++;
	(i == 4) && (LITTLE_PIVOTS = tab[st->count / 3]) && st->il++;
	(st->count > 420) && (LITTLE_PIVOTS = tab[a - st->count / 5]) && st->il++;
	while (st->count / i > 1)
	{
		(i == 4) && (st->little_pivots[st->il - 1] > tab[st->count / 3])
		&& (LITTLE_PIVOTS = tab[st->count / 3]) && st->il++;
		LITTLE_PIVOTS = tab[st->count / (int)i];
		st->il++ && (st->count > 900) ? (i *= 1.3) : (i *= 1.5);
	}
	(st->count > 420) && (st->big_pivots[st->ib] = tab[a + st->count / 18]) && st->ib++;
	(st->count > 75) && (st->big_pivots[st->ib] = tab[a + st->count / 10]) && st->ib++;
	(st->count > 200) && (st->big_pivots[st->ib] = tab[a + st->count / 5]) && st->ib++;
	i = 4;
	while ((a += st->count / (int)i) < st->count)
	{
		(st->big_pivots[st->ib] = tab[a]) && st->ib++;
		(st->count > 400) ? (i *= 3 - k) && (k += 0.5) : (i *= 2);
		if (tab[a] == st->big_pivots[st->ib - 1])
			(st->count > 400) ? (a += 8) : (a += 2);
	}
	(st->big_pivots[st->ib - 1] < tab[st->count - 4])
	? (st->big_pivots[st->ib] = tab[st->count - 4])
	: (st->big_pivots[st->ib - 1] = tab[st->count - 4]);
}

static int	sort_int(int *tab, unsigned int size, t_main *st)
{
	unsigned int	i;
	unsigned int	j;
	int				exchange;

	j = 0;
	if (!tab || !*tab)
		return (0);
	while (j < size)
	{
		i = j;
		while (i < size)
		{
			if (tab[j] > tab[i])
			{
				exchange = tab[j];
				tab[j] = tab[i];
				tab[i] = exchange;
			}
			i++;
		}
		j++;
	}
	pivots_searching(tab, st);
	return (tab[i / 2]);
}

int			median(t_stack *stack, t_main *st)
{
	unsigned int	i;
	t_stack			*tmp;
	int				*num;

	i = 0;
	if (!stack)
		return (false);
	tmp = stack;
	num = (int *)malloc(sizeof(int) * st->count);
	while (tmp)
	{
		num[i++] = tmp->digit;
		tmp = tmp->next;
	}
	return (sort_int(num, i, st));
}

void		validation(t_main *st, int argc, char **argv)
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
		while (argv[i] && is_num(argv[i]) && (sum += num) | 1)
			stack_create(&st->a, num = ft_atoi_spec(argv[i++]), st);
	}
	else
		while (i++ < argc - 1 && is_num(argv[i]) && (sum += num) | 1)
			stack_create(&st->a, num = ft_atoi_spec(argv[i]), st);
	if (is_sorted_stack_a(st->a, st))
		return ;
	bit_of_magic((st->first_p = median(st->a, st)), st);
}
