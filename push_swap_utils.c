/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:44:03 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/06 19:15:37 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *new_node(int val)
{
    t_node  *n;

    n = malloc(sizeof(t_node));
    if (!n)
        exit(1);
    n->value = val;
    n->next = NULL;
    return (n);
}

void    push_node(t_stack *s, t_node *n)
{
    if (!n)
        return ;
    n->next = s->top;
    s->top = n;
    s->size++;
}

t_node  *pop_node(t_stack *s)
{
    t_node *n;
    if (!s->top)
        return (NULL);
    n = s->top;
    s->top = n->next;
    n->next = NULL;
    s->size--;
    return (n);
}

void    free_stack(t_stack *s)
{
    t_node *cur;
    t_node *tmp;
    
    cur = s->top;
    while (cur)
    {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    s->top = NULL;
    s->size = 0;
}