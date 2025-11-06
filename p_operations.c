/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:41:39 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/06 19:57:09 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    op_push(t_stack *dst, t_stack *src, const char *op_name)
{
    t_node *n;
    n = pop_node(src);
    if (!n)
        return ;
    push_node(dst, n);
    write(1, op_name, ft_strlen(op_name));
    write(1, "\n", 1);
}

void    pa(t_stack *a, t_stack *b)
{
    op_push(a, b, "pa");
}
void    pb(t_stack *a, t_stack *b)
{
    op_push(b, a, "pb");
}