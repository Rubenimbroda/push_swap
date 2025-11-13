/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:41:39 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/13 10:57:00 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	op_push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	op_push(a, b);
	ft_printf("pb\n");
}
