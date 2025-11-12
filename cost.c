/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:17:37 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/12 15:31:07 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    get_cost(t_stack **a, t_stack **b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int     size_a;
    int     size_b;

    tmp_a = *a;
    tmp_b = *b;
    size_a = get_stack_size(tmp_a);
    size_b = get_stack_size(tmp_b);
    while (tmp_b)
    {
        tmp_b->cost_b = tmp_b->pos;
        if (tmp_b->pos > (size_b / 2))
            tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
        tmp_b->cost_a = tmp_b->should_pos;
        if (tmp_b->should_pos > (size_a / 2))
            tmp_b->cost_a = (size_a - tmp_b->should_pos) * -1;
        tmp_b = tmp_b->next;
    }
}

void    cheapest_move(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    int     cheapest;
    int     cost_a;
    int     cost_b;

    tmp = *b;
    cheapest = INT_MAX;
    while (tmp)
    {
        if (abs_val(tmp->cost_a) + abs_val(tmp->cost_b) < abs_val(cheapest))
        {
            cheapest = abs_val(tmp->cost_a) + abs_val(tmp->cost_b);
            cost_a = tmp->cost_a;
            cost_b = tmp->cost_b;
        }
        tmp = tmp->next;
    }
    choose_move(a, b, cost_a, cost_b);
}
