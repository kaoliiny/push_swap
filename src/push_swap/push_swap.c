/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/08 22:35:10 by kaoliiny         ###   ########.fr       */
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

	st.ib = 0;
	st.il = 0;
	st.a = NULL;
	st.b = NULL;
	st.count = argc - 1;
	if (argc <= 1)
		manage_error(1);
	validation(&st, argc, argv);
	return (0);
}
