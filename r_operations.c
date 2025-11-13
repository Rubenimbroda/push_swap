/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:50:02 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/13 10:53:53 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_last_element(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_stack **a)
{
	op_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	op_rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	op_rotate(a);
	op_rotate(b);
	ft_printf("rr\n");
}
