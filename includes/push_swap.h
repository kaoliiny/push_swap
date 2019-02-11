/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:14:48 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/02/11 21:42:45 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# include <unistd.h>

typedef struct t_stack
{
	int	digit;
	struct t_stack *next;
}	t_stack;

typedef struct t_main_st
{
	struct t_stack	*a;
	struct t_stack	*b;

	struct t_stack	*last_a;
	struct t_stack	*last_b;

	int		min;
	int		max;

	int		first_p;
	int		point;
	int		size_b;
	int		count;

}	t_main;

void	second_part_bit(int point, t_main *st, bool x);
int		shake_b(int point, int count, t_main *st);

void	manage_error(int errno);
void	validation(t_main *st, int argc, char **argv);

int		last_a(t_stack *stack);
int		is_sort(t_stack *stack, int point, t_main *st);
int		is_r_sort(t_stack *stack, int point, t_main *st);

t_stack	*ft_newlst(int integert);
void	stack_create(t_stack **a, int integer, t_main *st);

bool	push_stack(t_stack **dest, t_stack **src);
void	swap_first_el(t_stack *stack);
bool	rotate_a(t_stack **stack);
t_stack *rev_rotate(t_stack **stack, t_main *st);

void	bit(int point, t_main *st);
void	bit2(int point, t_main *st);
void	bit_of_magic(int point, t_main *st, bool x);

#endif