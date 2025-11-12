/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:55:18 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/12 12:17:40 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_all_save_3(t_stack **a, t_stack **b)
{
    int stack_size;
    int pushed;
    int i;

    stack_size = get_stack_size(*a);
    pushed = 0;
    i = 0;
    while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
    {
        if ((*a)->i <= stack_size / 2)
        {
            pb(a, b);
            pushed++;
        }
        else
            ra(a);
        i++;
    }
    while (stack_size - pushed > 3)
    {
        pb(a, b);
        pushed++;
    }
}

static void shift_stack(t_stack **a)
{
    int stack_size;
    int lowest_pos;

    stack_size = get_stack_size(*a);
    lowest_pos = get_lowest_pos(a);
    if (lowest_pos  > stack_size / 2)
    {
        while (lowest_pos < stack_size)
        {
            rra(a);
            lowest_pos++;
        }
    }
    else
    {
        while (lowest_pos > 0)
        {
            ra(a);
            lowest_pos--;
        }
    }
}

void    sort(t_stack **a, t_stack **b)
{
    push_all_save_3(a, b);
    sort_three(a);
    while (*b)
    {
        get_should_position(a, b);
        get_cost(a, b);
        cheapest_move(a, b);
    }
    if (!is_sorted(*a))
        shift_stack(a);
}
