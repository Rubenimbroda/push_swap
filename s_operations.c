/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:09:55 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/06 19:46:39 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_stack *s, const char *op_name)
{
	t_node *first;
	t_node *second;
	if (!s || s->size < 2)
		return ;
	first = pop_node(s);
	second = pop_node(s);
	push_node(s, first);
	push_node(s, second);
	write(1, op_name, ft_strlen(op_name));
	write(1, "\n", 1);
}

void	op_ss(t_stack *a, t_stack *b)
{
	t_node *first;
	t_node *second;
	
	if (a && a->size >= 2)
	{
		first = pop_node(a);
		second = pop_node(a);
		push_node(a, first);
		push_node(a, second);
	}
	if (b && b->size >= 2)
	{
		first = pop_node(b);
		second = pop_node(b);
		push_node(b, first);
		push_node(b, second);
	}
	write(1, "ss\n", 3);
}

void	sa(t_stack *a)
{
	op_swap(a, "sa");
}

void sb(t_stack *b)
{
	op_swap(b, "sb");
}

void	ss(t_stack *a, t_stack *b)
{
	op_ss(a, b);
}