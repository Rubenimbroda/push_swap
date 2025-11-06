/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:57:27 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/06 21:21:04 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    op_rev_rotate(t_stack *s, const char *op_name)
{
    t_node  *current;
    t_node  *previus;

    current = s->top;
    previus = NULL;
    if (!s ||s->size < 2)
        return ;
    while (current->next)
    {
        previus = current;
        current = current->next;
    }
    previus->next = NULL;
    current->next = s->top;
    s->top = current;
    write(1, op_name, ft_strlen(op_name));
    write(1, "\n", 1);
}

void op_rrr(t_stack *a, t_stack *b)
{
    t_node  *current;
    t_node  *previus;

    if (a && a->size >= 2)
    {
        current = a->top;
        previus = NULL;
        while (current->next)
        {
            previus = current;
            current = current->next;
        }
        previus->next = NULL;
        current->next = a->top;
        a->top = current;
    }
    if (b && b->size >= 2)
    {
        current = b->top;
        previus = NULL;
        while (current->next)
        {
            previus = current;
            current = current->next;
        }
        previus->next = NULL;
        current->next = b->top;
        b->top = current;
    }
    write(1, "rrr\n", 4);
}

void    rra(t_stack *a)
{
    op_rev_rotate(a, "rra");
}
void    rrb(t_stack *b)
{
    op_rev_rotate(b, "rrb");
}

void    rrr(t_stack *a, t_stack *b)
{
    op_rrr(a, b);
}