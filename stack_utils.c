/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:44:03 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/12 12:06:34 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_last_element(t_stack *stack)
{
    while (stack && stack->next != NULL)
        stack = stack->next;
    return (stack);
}

t_stack *get_before_last_element(t_stack *stack)
{
    while (stack && stack->next && stack->next->next != NULL)
        stack = stack->next;
    return (stack);
}

t_stack *new_element(int value)
{
    t_stack *new;

    new = malloc(sizeof * new);
    if (!new)
        return (NULL);
    new->value = value;
    new->i = 0;
    new->pos = -1;
    new->should_pos = -1;
    new->cost_a = -1;
    new->cost_b = -1;
    new->next = NULL;
    return (new);
}

void    stack_add_end(t_stack **stack, t_stack *new)
{
    t_stack *tail;

    if (!new)
        return ;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    tail = get_last_element(*stack);
    tail->next = new;
}

int get_stack_size(t_stack *stack)
{
    int size;

    size = 0;
    if (!stack)
        return (0);
    while (stack)
    {
        stack = stack->next;
        size++;
    }
    return (size);
}