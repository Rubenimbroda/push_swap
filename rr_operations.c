/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:57:27 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/10 10:38:50 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    op_rev_rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;
    t_stack *before_tail;

    tail = get_last_element(*stack);
    before_tail = get_before_last_element(*stack);
    tmp = *stack;
    *stack = tail;
    (*stack)->next = tmp;
    before_tail->next = NULL;
}

void    rra(t_stack **a)
{
    op_rev_rotate(a);
    ft_printf("rra\n");
}
void    rrb(t_stack **b)
{
    op_rev_rotate(b);
    ft_printf("rrb\n");
}

void    rrr(t_stack **a, t_stack **b)
{
    op_rev_rotate(a);
    op_rev_rotate(b);
    ft_printf("rrr\n");
}