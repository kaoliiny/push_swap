/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/04 00:39:59 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_error(int errno)
{
	const char *err_mes[42] = {"",
		"1. Oh no! Your stack is empty",
		"2. Seems like your stack consist not only the numbers",
		"3. Unfortunately your stack doesn't have a good numbers",
		"4. Sorry, you gave us not only the int numbers"
	};

	ft_putendl_fd(err_mes[errno], 2);
	exit(errno);
}

int		main(int argc, char **argv)
{
	t_main st;

	st.count = argc - 1;
	(argc > 1) ? (validation(&st, argc, argv))
	: manage_error(1);
	// system("leaks push_swap");
	return (0);
}
