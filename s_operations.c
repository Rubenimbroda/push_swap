/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:09:55 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/13 10:49:30 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->i;
	stack->i = stack->next->i;
	stack->next->i = tmp;
}

void	sa(t_stack **a)
{
	op_swap(*a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	op_swap(*b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	op_swap(*a);
	op_swap(*b);
	ft_printf("ss\n");
}
