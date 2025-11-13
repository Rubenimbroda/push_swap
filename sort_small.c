/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:55:21 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/13 10:48:15 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest_i(t_stack *stack)
{
	int	index;

	index = stack->i;
	while (stack)
	{
		if (stack->i > index)
			index = stack->i;
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_i(*stack);
	if ((*stack)->i == highest)
		ra(stack);
	else if ((*stack)->next->i == highest)
		rra(stack);
	if ((*stack)->i > (*stack)->next->i)
		sa(stack);
}
