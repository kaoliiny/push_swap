/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:14:48 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/09 17:56:58 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# include <unistd.h>

# define LITTLE_PIVOTS	st->little_pivots[st->il]
# define BIG_PIVOTS		st->big_pivots[st->ib]

# define A_DIGIT		st->a->digit
# define B_DIGIT		st->b->digit

# define A_N_D			st->a->next->digit

# define A_N_N_D		st->a->next->next->digit

typedef struct	s_stack
{
	int				digit;
	struct s_stack	*next;

}				t_stack;

typedef struct	s_main_st
{
	struct s_stack	*a;
	struct s_stack	*b;

	struct s_stack	*last_a;
	struct s_stack	*last_b;

	int				min;
	int				max;

	int				count;
	int				point;
	int				first_p;

	int				big_pivots[30];
	int				little_pivots[30];
	int				ib;
	int				il;

}				t_main;

void			manage_error(int errno);
void			validation(t_main *st, int argc, char **argv);

ssize_t			ft_atoi_spec(const char *str);

int				if_max(t_stack *stack, int digit);
int				is_sort(t_stack *stack);
bool			is_sorted_stack_a(t_stack *stack);

t_stack			*last_a(t_stack *stack);
t_stack			*ft_newlst(int integert);
void			stack_create(t_stack **a, int integer, t_main *st);

bool			push_stack(t_stack **dest, t_stack **src);
bool			swap_first_el(t_stack *stack);
bool			rotate_a(t_stack **stack);
t_stack			*rev_rotate(t_stack **stack, t_main *st);

void			bit(t_main *st);
void			bit_of_magic(int point, t_main *st);
void			one_more_bit(t_main *st);

bool			print_op(char op[5]);

#endif
