/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:50:02 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/06 20:15:41 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_stack *s, const char *op_name)
{
	t_node	*first;
	t_node	*current;
	
	first = pop_node(s);
	current = s->top;
	if (!s || s->size < 2)
		return ;
	if (!current)
	{
		push_node(s, first);
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	s->size++;
	s->size--;
	write(1, op_name, ft_strlen(op_name));
	write(1, "\n", 1);
}

void    op_rr(t_stack *a, t_stack *b)
{
    t_node *first;
    t_node *current;
    
    if (a && a->size >= 2)
    {
        first = pop_node(a);
        current = a->top;
        while (current->next)
            current = current->next;
        current->next = first;
        first->next = NULL;
        a->size++;
        a->size--;
    }
	if (b && b->size >= 2)
	{
		first = pop_node(b);
		current = b->top;
		while (current->next)
			current = current->next;
		current->next = first;
		first = NULL;
		b->size++;
		b->size--;
	}
	write(1, "rr\n", 3);
}

void	ra(t_stack *a)
{
	op_rotate(a, "ra");
}

void	rb(t_stack *b)
{
	op_rotate(b, "rb");
}

void	rr(t_stack *a, t_stack *b)
{
	op_rr(a, b);
}