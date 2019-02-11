/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pa_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:21:43 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/02/10 17:14:22 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    push_stack(t_stack **dest, t_stack **src)
{
    t_stack *tmp;

    tmp = *dest;
    if (!src || !dest || !*src)
        return (false);
    if (!*dest)
        *dest = ft_newlst((*src)->digit);
    else
    {
       tmp = ft_newlst((*src)->digit);
       tmp->next = *dest;
       *dest = tmp;
    }
    *src = (*src)->next;
    return (true);
}

void    swap_first_el(t_stack *stack)
{
    int el;

    if (!stack || !stack->next)
        return ;
    el = stack->digit;
    stack->digit = stack->next->digit;
    stack->next->digit = el;
}

bool    rotate_a(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack)
        return (false);
    tmp = *stack;
    while(tmp)
    {
        if (tmp->next == NULL)
        {
            tmp->next = ft_newlst((*stack)->digit);
            break ;
        }
        tmp = tmp->next;
    }
    *stack = (*stack)->next;
    return(true);
}

t_stack *rev_rotate(t_stack **stack, t_main *st)
{
    t_stack *tmp;
    t_stack *last;

    if (!stack)
        return (NULL);
    tmp = *stack;
    while(tmp)
    {
        if (tmp->next != NULL)
            st->last_a = tmp;
        else
        {
            last = tmp;
           // free(tmp);
           // tmp->next = NULL;
            last->next = *stack;
            st->last_a->next = NULL;
            return(last);
        }
        tmp = tmp->next;
    }
    return (NULL);
}